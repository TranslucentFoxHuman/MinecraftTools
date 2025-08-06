#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "globalvars.h"

#include <string>
#include <iostream>
#include <QString>
#include <QDesktopServices>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Set Minecraft Wiki URL
    ui->MinecraftWikiLink->setText(QString::fromStdString(std::string("<a href=\"" + minecraftWikiUrl + "\">" + minecraftWikiUrl + "</a>")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// OverWorld and Nether coordinate converter
void MainWindow::on_OverWorldX_textChanged(const QString &arg1)
{
    ui->NetherX->setValue(ui->OverWorldX->text().toInt() / 8);
}
void MainWindow::on_OverWorldZ_textChanged(const QString &arg1)
{
    ui->NetherZ->setValue(ui->OverWorldZ->text().toInt() / 8);
}
void MainWindow::on_NetherX_textChanged(const QString &arg1)
{
    ui->OverWorldX->setValue(ui->NetherX->text().toInt() * 8);
}
void MainWindow::on_NetherZ_textChanged(const QString &arg1)
{
    ui->OverWorldZ->setValue(ui->NetherZ->text().toInt() * 8);
}


void MainWindow::on_WikiSearchButton_clicked()
{
    QDesktopServices::openUrl(QString::fromStdString(std::string(minecraftWikiUrl + "?search=" + ui->WikiSearchText->text().toStdString())));
}
void MainWindow::on_WikiSearchText_returnPressed()
{
    MainWindow::on_WikiSearchButton_clicked();
}


void MainWindow::on_actionAbout_triggered() {
    AboutDialog *abtdiag = new AboutDialog;
    abtdiag->exec();
}
