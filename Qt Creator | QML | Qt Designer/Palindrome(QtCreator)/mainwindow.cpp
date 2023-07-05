#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QString>

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


void MainWindow::on_pushButton_clicked()
{
    QString word = QString(ui->lineEdit->text());
    int i,n = word.length();
    for(i = 0; i < n/2; i++)
    {
        if(word[i] != word[n-i-1])
        {
            QMessageBox::information(this, "The word - ", QString(word + " isn't a palindrom"));
            return;
        }
    }
    QMessageBox::information(this, "The word - ", QString(word + " is a palindrom"));
}

