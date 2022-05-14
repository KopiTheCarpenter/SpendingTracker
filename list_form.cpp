#include "list_form.h"
#include "ui_list_form.h"

List_form::List_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::List_form)
{
    ui->setupUi(this);
}

List_form::~List_form()
{
    delete ui;
}
