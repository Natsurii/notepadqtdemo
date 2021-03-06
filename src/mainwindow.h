#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSave_triggered();

    void on_actionNew_triggered();


    void on_actionOpen_triggered();

    void on_actionAdd_Time_Date_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionZoom_In_triggered();

    void on_actionAbout_QT_triggered();

    void on_actionAbout_the_Developer_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
