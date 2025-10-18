#include "audiowindow.h"
#include "ui_audiowindow.h"

audiowindow::audiowindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::audiowindow)
{
    ui->setupUi(this);
}

audiowindow::~audiowindow()
{
    delete ui;
}

void audiowindow::on_selectFileButton_clicked()
{
    inputFilePath = QFileDialog::getOpenFileName(this, "Choisir un fichier audio", "", "Audios (*.mp3 *.wav *.ogg *.flac *.aac)");
    ui->filePathLabel->setText(inputFilePath);
}

void audiowindow::on_convertButton_clicked()
{
    if (inputFilePath.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez choisir un fichier audio d'abord !");
        return;
    }

    QString outputFormat = ui->formatComboBox->currentText().toLower();
    QString outputPath = QFileDialog::getSaveFileName(this, "Enregistrer sous", "", "Audio (*." + outputFormat + ")");
    if (outputPath.isEmpty()) return;

    QString program = "ffmpeg";
    QStringList arguments;
    arguments << "-i" << inputFilePath << outputPath;

    QProcess process;
    process.start(program, arguments);
    process.waitForFinished(-1);

    if (process.exitStatus() == QProcess::NormalExit && process.exitCode() == 0)
        QMessageBox::information(this, "Succès", "Audio converti avec succès !");
    else
        QMessageBox::critical(this, "Erreur", "La conversion a échoué.\nAssurez-vous que FFmpeg est installé et accessible.");
}
