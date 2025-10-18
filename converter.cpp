#include "converter.h"
#include <QDebug>

Converter::Converter(QObject *parent)
    : QObject(parent),
    process(new QProcess(this))
{
    connect(process, &QProcess::readyReadStandardOutput, this, [=]() {
        QString output = QString::fromUtf8(process->readAllStandardOutput());
        emit conversionProgress(output);
    });

    connect(process, &QProcess::readyReadStandardError, this, [=]() {
        QString output = QString::fromUtf8(process->readAllStandardError());
        emit conversionProgress(output);
    });

    connect(process, qOverload<int, QProcess::ExitStatus>(&QProcess::finished),
            this, [=](int exitCode, QProcess::ExitStatus status) {
                bool success = (status == QProcess::NormalExit && exitCode == 0);
                emit conversionFinished(success, success ? "Conversion terminée avec succès ✅" :
                                                     "Échec de la conversion ❌");
            });
}

QStringList Converter::buildFFmpegArguments(const QString &inputPath,
                                            const QString &outputPath,
                                            FileType type)
{
    QStringList args;
    args << "-y" << "-i" << inputPath; // -y = overwrite sans demander

    switch (type) {
    case FileType::Image:
        // Qualité maximale sans perte pour images
        args << "-qscale:v" << "1" << outputPath;
        break;

    case FileType::Video:
        // Conversion vidéo haute qualité
        args << "-c:v" << "libx264"      // bon codec vidéo
             << "-preset" << "slow"      // meilleur ratio qualité/temps
             << "-crf" << "18"           // qualité quasi sans perte
             << "-c:a" << "aac"
             << "-b:a" << "192k"
             << outputPath;
        break;

    case FileType::Audio:
        // Conversion audio haute qualité
        args << "-vn"                   // pas de flux vidéo
             << "-c:a" << "libmp3lame"  // bon codec audio
             << "-q:a" << "2"           // haute qualité MP3 (0 = max)
             << outputPath;
        break;
    }

    return args;
}

void Converter::convertFile(const QString &inputPath,
                            const QString &outputPath,
                            FileType type)
{
    if (process->state() != QProcess::NotRunning) {
        emit conversionFinished(false, "Une conversion est déjà en cours !");
        return;
    }

    QString program = "ffmpeg";
    QStringList args = buildFFmpegArguments(inputPath, outputPath, type);

    emit conversionProgress("Démarrage de FFmpeg...\n");

    process->start(program, args);
}
