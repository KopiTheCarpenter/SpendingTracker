#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QMainWindow>
#include <QSqlDatabase>

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

private:
    Ui::MainWindow *ui;


public:
    QSqlDatabase db;
    QString application_location = QCoreApplication::applicationDirPath();
private:
    QString file_path;
};
#endif // MAINWINDOW_H
