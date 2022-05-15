#include "myconfig.cpp"
#include "expenditure.h"
#include "add_expenditures_form.h"
#include "ui_add_expenditures_form.h"


#include <QDate>
#include <QMessageBox>

Add_Expenditures_form::Add_Expenditures_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_Expenditures_form)
{
    ui->setupUi(this);
}

Add_Expenditures_form::~Add_Expenditures_form()
{
    delete ui;
}

void Add_Expenditures_form::showEvent(QShowEvent *event){
    if(MyConfig::DB_URL == ""){
        ui->label_warning->setEnabled(true);
        ui->btn_OK->setEnabled(false);
        ui->label_warning->setText("Database is not selected!");
    }else{
        ui->label_warning->setEnabled(false);
        ui->label_warning->setText("");
        ui->btn_OK->setEnabled(true);
    }

    ui->dateEdit->setDate(QDate::currentDate());
    qDebug() << ui->dateEdit->date().day();
}

void Add_Expenditures_form::on_btn_OK_clicked()
{
    QString name,itemType, amountDescription;
    uint value, amount, year, month, day;
    name= ui->nameLineEdit->text();
    itemType = ui->itemTypeLineEdit->text();
    amountDescription = ui->amountDescriptionLineEdit->text();
    value = ui->valueLineEdit->text().toUInt();
    amount = ui->amountLineEdit->text().toUInt();
    year = ui->dateEdit->date().year();
    month = ui->dateEdit->date().month();
    day = ui->dateEdit->date().day();
    Expenditure exp(name,itemType,amountDescription,value,amount,year,month,day);
    QMessageBox msgBox;
    if(dbc.addExpenditure(exp)){
        msgBox.setText("Expenditure added to database.");
        this->close();
    }
    else{
        msgBox.setText("Something went wrong.");
    }
    msgBox.exec();
    clearForm();
}

void Add_Expenditures_form::on_btn_Close_clicked()
{
    clearForm();
    this->close();
}

void Add_Expenditures_form::clearForm()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

