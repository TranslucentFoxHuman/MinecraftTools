#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_OverWorldX_textChanged(const QString &arg1);

    void on_OverWorldZ_textChanged(const QString &arg1);

    void on_NetherX_textChanged(const QString &arg1);

    void on_NetherZ_textChanged(const QString &arg1);

    void on_WikiSearchButton_clicked();

    void on_WikiSearchText_returnPressed();

    void on_actionAbout_triggered();

    void on_StrengthAllowCheat_toggled(bool checked);

    void on_SpeedAllowCheat_toggled(bool checked);

    void on_JumpAllowCheat_toggled(bool checked);

    void on_MobGenerateButton_clicked();

    void on_MobGenCopy_clicked();

    void on_mainTab_currentChanged(int index);

    //Tools menu actions
    void on_actionCoordinate_triggered();
    void on_actionWiki_triggered();
    void on_actionMob_Generator_triggered();
    void on_actionMemo_triggered();

private:
    Ui::MainWindow *ui;

    void GenerateHorse();
    void HideMobGenAll();
    void ShowMobGen();

};
#endif // MAINWINDOW_H
