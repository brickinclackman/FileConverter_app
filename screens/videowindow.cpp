#include "videowindow.h"
#include "ui_videowindow.h"

videowindow::videowindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::videowindow)
{
    ui->setupUi(this);
}

videowindow::~videowindow()
{
    delete ui;
}

void videowindow::on_selectFileButton_clicked()
{
    inputFilePath = QFileDialog::getOpenFileName(this, "Choisir une vidéo", "", "Vidéos (*.mp4 *.mov *.avi *.webm *.mkv)");
    ui->filePathLabel->setText(inputFilePath);
}

void videowindow::on_convertButton_clicked()
{
    if (inputFilePath.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez choisir une vidéo d'abord !");
        return;
    }

    QString outputFormat = ui->formatComboBox->currentText().toLower();
    QString outputPath = QFileDialog::getSaveFileName(this, "Enregistrer sous", "", "Vidéo (*." + outputFormat + ")");
    if (outputPath.isEmpty()) return;

    QString program = "ffmpeg";
    QStringList arguments;
    arguments << "-i" << inputFilePath << outputPath;

    QProcess process;
    process.start(program, arguments);
    process.waitForFinished(-1);

    if (process.exitStatus() == QProcess::NormalExit && process.exitCode() == 0)
        QMessageBox::information(this, "Succès", "Vidéo convertie avec succès !");
    else
        QMessageBox::critical(this, "Erreur", "La conversion a échoué.\nAssurez-vous que FFmpeg est installé et accessible.");
}
