#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>

int fontSize = 16;
int fontSizeIncrement = 1;
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


void MainWindow::on_actionSave_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save the file to...", QDir::homePath());
    QFile fileSave(filePath);
    if (fileSave.open(QFile::WriteOnly)){
        QTextStream out(&fileSave);
        out << ui->textEdit->toPlainText();

        fileSave.flush();
        fileSave.close();
    }

}


void MainWindow::on_actionNew_triggered()
{
    if(!ui->textEdit->toPlainText().isEmpty()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Do you want to create a new text without saving?",
                                 QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes){
            ui->textEdit->clear();
        }
    }
}





void MainWindow::on_actionOpen_triggered()
{
    if(!ui->textEdit->toPlainText().isEmpty()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Do you want to open a text without saving?",
                                 QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes){
           ui->textEdit->clear();
            }
        }

    QString filePath = QFileDialog::getOpenFileName(this, "Open the file to...", QDir::homePath());
    QFile openFile(filePath);

    if(openFile.open(QFile::ReadOnly)){
        QTextStream in(&openFile);
        ui->textEdit->setText(in.readAll());
    }
}


void MainWindow::on_actionAdd_Time_Date_triggered()
{
    QString temp = ui->textEdit->toPlainText();
    temp += QDateTime::currentDateTime().toString();
    ui->textEdit->setText(temp);
}


void MainWindow::on_actionZoom_Out_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->selectAll();
    fontSize -= fontSizeIncrement;
    ui->textEdit->setFontPointSize(fontSize);
    ui->textEdit->setTextCursor( cursor );
}


void MainWindow::on_actionZoom_In_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    ui->textEdit->selectAll();
    fontSize += fontSizeIncrement;
    ui->textEdit->setFontPointSize(fontSize);
    ui->textEdit->setTextCursor( cursor );
}


void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this);
}


void MainWindow::on_actionAbout_the_Developer_triggered()
{
    QMessageBox::about(this, "About the developer.", "Developed by: Tan malakas");
}

