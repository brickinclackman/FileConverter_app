#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include <QProcess>
#include <QString>

class Converter : public QObject
{
    Q_OBJECT

public:
    explicit Converter(QObject *parent = nullptr);

    enum class FileType {
        Image,
        Video,
        Audio
    };

    // Conversion principale
    void convertFile(const QString &inputPath,
                     const QString &outputPath,
                     FileType type);

signals:
    void conversionProgress(QString outputLine);
    void conversionFinished(bool success, QString message);

private:
    QProcess *process;

    QStringList buildFFmpegArguments(const QString &inputPath,
                                     const QString &outputPath,
                                     FileType type);
};

#endif // CONVERTER_H
