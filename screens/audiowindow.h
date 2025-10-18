#ifndef AUDIOWINDOW_H
#define AUDIOWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class audiowindow;
}

class audiowindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit audiowindow(QWidget *parent = nullptr);
    ~audiowindow();

private slots:
    void on_selectFileButton_clicked();
    void on_convertButton_clicked();

private:
    Ui::audiowindow *ui;
    QString inputFilePath;
};

#endif // AUDIOWINDOW_H
