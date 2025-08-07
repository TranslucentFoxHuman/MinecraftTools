#include "mainwindow.h"
#include "globalvars.h"

#include <QTranslator>
#include <QObject>
#include <QApplication>
#include <QLocale>

std::string minecraftWikiUrl;
std::string versionString = "1.2.1";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator ts;
    if (QLocale::system().name().toStdString() == "ja_JP") {
        ts.load(":/translations/minecrafttools_ja_JP.qm");
        a.installTranslator(&ts);
    }
    minecraftWikiUrl = QObject::tr("https://minecraft.wiki/").toStdString();
    MainWindow w;
    w.show();
    return a.exec();
}
