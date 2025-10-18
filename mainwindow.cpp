#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "screens/imagewindow.h"
#include "screens/videowindow.h"
#include "screens/audiowindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_imageButton_clicked()
{
    imagewindow *w = new imagewindow(this);
    w->show();
}

void MainWindow::on_videoButton_clicked()
{
    videowindow *w = new videowindow(this);
    w->show();
}

void MainWindow::on_audioButton_clicked()
{
    audiowindow *w = new audiowindow(this);
    w->show();
}
