#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myconfig.cpp"
#include "add_expenditures_form.h"
#include "databasecontroller.h"
#include "list_expenditures_form.h"


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
    void on_actionAbout_triggered();

    void on_actionSelect_database_triggered();

    void on_actionCreate_database_triggered();

    void on_actionAdd_Expenditure_triggered();
    void on_actionList_Expenditures_triggered();

    void on_actionSumm_Expenditures_triggered();

    void on_actionSumm_Expenditures_thi_month_triggered();

    void on_actionSumm_Expenditures_this_year_triggered();

private:
    Ui::MainWindow *ui;


public:
    Add_Expenditures_form aedf;
    List_Expenditures_form ledf;
private:
    QString file_path;
    DatabaseController dbc;
};
#endif // MAINWINDOW_H
