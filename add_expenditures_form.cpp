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

void Add_Expenditures_form::on_buttonBox_accepted()
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
    msgBox.setText("ACCEPTED");
}


void Add_Expenditures_form::on_buttonBox_rejected()
{
    QMessageBox msgBox;
    msgBox.setText("REJECTED");
}

