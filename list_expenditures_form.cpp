#include "databasecontroller.h"
#include "list_expenditures_form.h"
#include "ui_list_expenditures_form.h"

#include <QSqlQuery>
#include <QSqlQueryModel>

List_Expenditures_form::List_Expenditures_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::List_Expenditures_form)
{
    ui->setupUi(this);
}

List_Expenditures_form::~List_Expenditures_form()
{
    delete ui;
}

void List_Expenditures_form::showEvent(QShowEvent *event){
    DatabaseController dbc;
    dbc.connectToDatabase();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from expenditures;");
    model->setHeaderData(0,Qt::Horizontal, tr("id"));
    model->setHeaderData(1,Qt::Horizontal, tr("name"));
    model->setHeaderData(2,Qt::Horizontal, tr("item_type"));
    model->setHeaderData(3,Qt::Horizontal, tr("amount_description"));
    model->setHeaderData(4,Qt::Horizontal, tr("value"));
    model->setHeaderData(5,Qt::Horizontal, tr("amount"));
    ui->tableView->setModel(model);
    dbc.closeDatabase();
}
