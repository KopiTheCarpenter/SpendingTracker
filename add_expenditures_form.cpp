#include "add_expenditures_form.h"
#include "expenditure.h"
#include "ui_add_expenditures_form.h"

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

void Add_Expenditures_form::on_btn_OK_clicked()
{
    QString name,itemType, amountDescription;
    uint value, amount;
    name= ui->nameLineEdit->text();
    itemType = ui->itemTypeLineEdit->text();
    amountDescription = ui->amountDescriptionLineEdit->text();
    value = ui->valueLineEdit->text().toUInt();
    amount = ui->amountLineEdit->text().toUInt();
    Expenditure exp(name,itemType,amountDescription,value,amount);
    QMessageBox msgBox;
    if(dbc.addExpenditure(exp)){
        msgBox.setText("Expenditure added to database.");
        this->close();
    }
    else{
        msgBox.setText("Something went wrong.");
    }
    msgBox.exec();

}


void Add_Expenditures_form::on_btn_Close_clicked()
{
    this->close();
}

