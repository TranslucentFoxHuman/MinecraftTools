#include "mainwindow.h"
#include "globalvars.h"

#include <QTranslator>
#include <QObject>
#include <QApplication>

std::string minecraftWikiUrl;
std::string versionString = "1.2";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator ts;
    if (std::string(setlocale(LC_ALL,NULL)) == "ja_JP.UTF-8" || std::string(setlocale(LC_ALL,NULL)) == "ja_JP.EUC-JP") {
        ts.load(":/translations/minecrafttools_ja_JP.qm");
        a.installTranslator(&ts);
    }
    minecraftWikiUrl = QObject::tr("https://minecraft.wiki/").toStdString();
    MainWindow w;
    w.show();
    return a.exec();
}
