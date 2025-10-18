#include "imagewindow.h"
#include "ui_imagewindow.h"

imagewindow::imagewindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::imagewindow)
{
    ui->setupUi(this);
}

imagewindow::~imagewindow()
{
    delete ui;
}

void imagewindow::on_selectFileButton_clicked()
{
    inputFilePath = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");
    ui->filePathLabel->setText(inputFilePath);
}

void imagewindow::on_convertButton_clicked()
{
    if (inputFilePath.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez choisir un fichier d'abord !");
        return;
    }

    QString outputFormat = ui->formatComboBox->currentText().toLower();
    QImage image;
    if (!image.load(inputFilePath)) {
        QMessageBox::warning(this, "Erreur", "Impossible de charger l'image !");
        return;
    }

    QString outputPath = QFileDialog::getSaveFileName(this, "Enregistrer sous", "", "Image (*." + outputFormat + ")");
    if (outputPath.isEmpty()) return;

    if (image.save(outputPath, outputFormat.toUpper().toUtf8().constData())) {
        QMessageBox::information(this, "Succès", "Image convertie avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "La conversion a échoué.");
    }
}
