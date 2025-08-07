#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "globalvars.h"

#include <string>
#include <iostream>
#include <QString>
#include <QDesktopServices>
#include <QUrl>
#include <QClipboard>


std::string truncateZero(std::string base){
    if (base.find_last_not_of('0') != std::string::npos) {
        base.erase(base.find_last_not_of('0') + 1,base.length() - 1);
    }
    if (base.at(base.length()-1) == '.') {
        base.erase(base.length());
    }
    return base;
}

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

void MainWindow::HideMobGenAll() {
    ui->HorseGenWidget->hide();
}
void MainWindow::ShowMobGen() {
    switch (ui->MobType->currentIndex()) {
        case 0:
            ui->HorseGenWidget->show();
        break;
    }
}


void MainWindow::on_mainTab_currentChanged(int index)
{
    HideMobGenAll();
    ShowMobGen();
}


// Menu Actions
// *Application
void MainWindow::on_actionAbout_triggered() {
    AboutDialog *abtdiag = new AboutDialog;
    abtdiag->exec();
}

// *Tools
void MainWindow::on_actionCoordinate_triggered(){
    ui->mainTab->setCurrentIndex(0);
}
void MainWindow::on_actionWiki_triggered(){
    ui->mainTab->setCurrentIndex(1);
}
void MainWindow::on_actionMob_Generator_triggered(){
    ui->mainTab->setCurrentIndex(2);
}
void MainWindow::on_actionMemo_triggered(){
    ui->mainTab->setCurrentIndex(3);
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




// Horse Generator

void MainWindow::GenerateHorse() {
    int variant = 256 * ui->PatternCombo->currentIndex();
    variant += ui->ColorCombo->currentIndex();
    std::string speedStr = truncateZero(std::to_string(ui->SpeedDouble->value()));
    std::string jumpStr = truncateZero(std::to_string(ui->JumpDouble->value()));
    std::string output = "/summon horse ~ ~ ~ {attributes:[{id:\"max_health\",base:" + std::to_string(ui->StrengthNum->value()) + "},{id:\"movement_speed\",base:" + speedStr + "},{id:\"jump_strength\",base:" + jumpStr + "}],Variant:" + std::to_string(variant);
    if (ui->horseTamed->isChecked()) {
        output = output + ",Tamed:true";
    }
    if (ui->HorseHasSaddle->isChecked()) {
        output = output + ",equipment:{saddle:{id:\"saddle\",count:1}}";
    }
    output = output + "}";
    ui->MobGenOut->setPlainText(QString::fromStdString(output));
}

// * Allow Cheats
void MainWindow::on_StrengthAllowCheat_toggled(bool checked) {
    if(checked) {
        ui->StrengthNum->setMaximum(60);
    } else {
        ui->StrengthNum->setMaximum(30);
    }
}
void MainWindow::on_SpeedAllowCheat_toggled(bool checked) {
    if (checked) {
        ui->SpeedDouble->setMaximum(1.0);
    } else {
        ui->SpeedDouble->setMaximum(0.3375);
    }
}
void MainWindow::on_JumpAllowCheat_toggled(bool checked) {
    if (checked) {
        ui->JumpDouble->setMaximum(100);
    } else {
        ui->JumpDouble->setMaximum(1.0);
    }
}


void MainWindow::on_MobGenerateButton_clicked()
{
    switch (ui->MobType->currentIndex()) {
        case 0:
            MainWindow::GenerateHorse();
        break;
    }
}


void MainWindow::on_MobGenCopy_clicked()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(ui->MobGenOut->toPlainText());
}




