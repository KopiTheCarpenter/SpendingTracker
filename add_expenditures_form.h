#ifndef ADD_EXPENDITURES_FORM_H
#define ADD_EXPENDITURES_FORM_H

#include "databasecontroller.h"

#include <QWidget>

namespace Ui {
class Add_Expenditures_form;
}

class Add_Expenditures_form : public QWidget
{
    Q_OBJECT

public:
    explicit Add_Expenditures_form(QWidget *parent = nullptr);
    ~Add_Expenditures_form();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::Add_Expenditures_form *ui;
    DatabaseController dbc;
};

#endif // ADD_EXPENDITURES_FORM_H
