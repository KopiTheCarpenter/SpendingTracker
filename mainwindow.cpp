#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

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


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Made by: Ács Koppány(CKE7XE)");
    msgBox.setWindowTitle("About");
    msgBox.exec();
}

void MainWindow::on_actionSelect_database_triggered()
{
    file_path =  QFileDialog::getOpenFileName(this, "Choose profile to be loaded!"),application_location+"/databases/";
    ui->VALAMIKELL->setText(application_location+"/databases/");
    if (!file_path.isEmpty())
        {
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName(file_path);
            //db.setHostName("bigblue");
            //db.setUserName("acarlson");
            //db.setPassword("1uTbSbAs");
            bool db_ok = db.open();
            QMessageBox msgBox;
            if(!db_ok){
                msgBox.setText("Error connecting to sqlite database: " + file_path);
                msgBox.exec();
            }
            else{
                msgBox.setText("Connected to sqlite database: " + file_path);
                msgBox.exec();
            }
            db.close();
        }
}

void MainWindow::on_actionCreate_database_triggered()
{
    QDir dir(application_location+ "/databases/");
    if (!dir.exists()){
      dir.mkpath(".");
    }
    QFileDialog fdialog;
    fdialog.setFileMode(QFileDialog::AnyFile);
    QString strFile = fdialog.getSaveFileName(NULL, "Create New File",dir.absolutePath(),"*.db");
    //qDebug()<<strFile;
    QFile file(strFile);
    file.open(QIODevice::WriteOnly);
    file.close();
}

