#include "add_income_form.h"
#include "ui_add_income_form.h"

Add_Income_Form::Add_Income_Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Income_Form)
{
    ui->setupUi(this);
}

Add_Income_Form::~Add_Income_Form()
{
    delete ui;
}
