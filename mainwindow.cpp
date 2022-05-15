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
    file_path =  QFileDialog::getOpenFileName(this, "Choose database to be loaded!",MyConfig::APPLICATION_LOCATION+"/databases/","*.db");
    ui->VALAMIKELL->setText(MyConfig::APPLICATION_LOCATION+"/databases/");
    if (!file_path.isEmpty())
        {
            MyConfig::DB_URL = file_path;
            bool db_ok = dbc.connectToDatabase(file_path);
            QMessageBox msgBox;
            if(!db_ok){
                msgBox.setText("Error connecting to sqlite database: " + MyConfig::DB_URL);
                msgBox.exec();
            }
            else{
                msgBox.setText("Connected to sqlite database: " + file_path);
                msgBox.exec();
            }
        }
}

void MainWindow::on_actionCreate_database_triggered()
{
    QDir dir(MyConfig::APPLICATION_LOCATION+ "/databases/");
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
    dbc.connectToDatabase(strFile);
    dbc.createSchema();
}


void MainWindow::on_actionAdd_Expenditure_triggered()
{
    aedf.setAttribute(Qt::WA_DeleteOnClose);
    aedf.show();
}

