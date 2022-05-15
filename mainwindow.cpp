#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyConfig::APPLICATION_LOCATION = QCoreApplication::applicationDirPath();
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
    QDir dir(MyConfig::APPLICATION_LOCATION+ "/databases/");
    file_path =  QFileDialog::getOpenFileName(this, "Choose database to be loaded!",dir.absolutePath(),"*.db");
    ui->VALAMIKELL->setText(MyConfig::APPLICATION_LOCATION+"/databases/");
    if (!file_path.isEmpty())
        {
            MyConfig::DB_URL = file_path;
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
    MyConfig::DB_URL = strFile;
    dbc.createSchema();
}


void MainWindow::on_actionAdd_Expenditure_triggered()
{
    aedf.setAttribute(Qt::WA_QuitOnClose);
    aedf.show();
}

