#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Asus-PC/Desktop/background.png");
        ui->background->setPixmap(pix);
  ui->background1->setPixmap(pix);


}

MainWindow::~MainWindow()
{
    delete ui;
}
