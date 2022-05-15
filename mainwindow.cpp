#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QDate>

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
    if (!file_path.isEmpty())
        {
            MyConfig::DB_URL = file_path;
            QMessageBox qmb;
            qmb.setText("Database choosen: "+MyConfig::DB_URL);
            qmb.exec();
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


void MainWindow::on_actionList_Expenditures_triggered()
{
    ledf.setAttribute(Qt::WA_QuitOnClose);
    ledf.show();
}


void MainWindow::on_actionSumm_Expenditures_triggered()
{
    QMessageBox qmb;
    dbc.connectToDatabase();
    QSqlQuery query;
    query.exec("Select SUM(value) from expenditures;");
    query.first();
    qmb.setText("Total Expenditure value: "+query.value(0).toString());
    qmb.exec();
    dbc.closeDatabase();
}


void MainWindow::on_actionSumm_Expenditures_thi_month_triggered()
{
    QMessageBox qmb;
    dbc.connectToDatabase();
    QSqlQuery query;
    QDate now = QDate::currentDate();
    query.prepare("Select SUM(value) from expenditures where year = ? AND month = ?;");
    query.addBindValue(now.year());
    query.addBindValue(now.month());
    query.exec();
    query.first();
    qmb.setText("Total Expenditure value this month: "+query.value(0).toString());
    qmb.exec();
    dbc.closeDatabase();
}


void MainWindow::on_actionSumm_Expenditures_this_year_triggered()
{
    QMessageBox qmb;
    dbc.connectToDatabase();
    QSqlQuery query;
    QDate now = QDate::currentDate();
    query.prepare("Select SUM(value) from expenditures where year = ?;");
    query.addBindValue(now.year());
    query.exec();
    query.first();
    qmb.setText("Total Expenditure value this year: "+query.value(0).toString());
    qmb.exec();
    dbc.closeDatabase();
}

