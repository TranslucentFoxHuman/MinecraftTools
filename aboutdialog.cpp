#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "globalvars.h"

#include <QString>

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->versionNumber->setText(QString::fromStdString(versionString));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
