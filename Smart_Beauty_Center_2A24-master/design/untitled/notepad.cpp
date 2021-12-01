#include "notepad.h"
#include "ui_notepad.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "mainwindow.h"

Notepad::Notepad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
}

Notepad::~Notepad()
{
    delete ui;
}



void Notepad::on_New_clicked()
{
    MainWindow s;
    s.Get_speak()->say("Nouveau fichier");
    file_path="";
    ui->textEdit->setText("");
}

void Notepad::on_Open_clicked()
{
    QString file_name= QFileDialog::getOpenFileName(this,"Open file");
    QFile f(file_name);
    file_path=file_name;
    if(!f.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"...","File not open");

    }else
    {
        QTextStream in(&f);
        QString text=in.readAll();
        ui->textEdit->setText(text);
        f.close();
    }
}

void Notepad::on_Save_clicked()
{
    QFile f(file_path);
    if(!f.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"...","File not open");

    }else
    {
        QTextStream out(&f);
        QString text=ui->textEdit->toPlainText();
        out<<text;
        f.flush();
        f.close();
    }
}

void Notepad::on_pushButton_4_clicked()
{
    QString file_name= QFileDialog::getSaveFileName(this,"Open file");
    QFile f(file_name);
    if(!f.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"...","File not open");

    }else
    {
        QTextStream out(&f);
        QString text=ui->textEdit->toPlainText();
        out<<text;
        f.flush();
        f.close();
    }
}

void Notepad::on_Copy_clicked()
{
    ui->textEdit->copy();
}

void Notepad::on_Paste_clicked()
{
    ui->textEdit->paste();
}

void Notepad::on_Cut_clicked()
{
    ui->textEdit->cut();

}

void Notepad::on_pushButton_10_clicked()
{
    ui->textEdit->undo();
}

void Notepad::on_Redo_clicked()
{
    ui->textEdit->redo();
}

void Notepad::on_pushButton_2_clicked()
{
    QString text;
    text+="Author: Oussema Ayari\n";
    text+="Date: 17/11/2021\n";
    text+="NotePad:(C) Notepad (R)\n";

    QMessageBox::about(this,"About Noptepad",text);
}

