#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class videowindow;
}

class videowindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit videowindow(QWidget *parent = nullptr);
    ~videowindow();

private slots:
    void on_selectFileButton_clicked();
    void on_convertButton_clicked();

private:
    Ui::videowindow *ui;
    QString inputFilePath;
};

#endif // VIDEOWINDOW_H
