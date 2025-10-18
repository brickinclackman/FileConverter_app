#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImage>
#include <QMessageBox>

namespace Ui {
class imagewindow;
}

class imagewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit imagewindow(QWidget *parent = nullptr);
    ~imagewindow();

private slots:
    void on_selectFileButton_clicked();
    void on_convertButton_clicked();

private:
    Ui::imagewindow *ui;
    QString inputFilePath;
};

#endif // IMAGEWINDOW_H
