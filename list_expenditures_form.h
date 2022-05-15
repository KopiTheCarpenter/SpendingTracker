#ifndef LIST_EXPENDITURES_FORM_H
#define LIST_EXPENDITURES_FORM_H

#include <QWidget>

namespace Ui {
class List_Expenditures_form;
}

class List_Expenditures_form : public QWidget
{
    Q_OBJECT

public:
    explicit List_Expenditures_form(QWidget *parent = nullptr);
    ~List_Expenditures_form();

    void showEvent(QShowEvent *event);
private:
    Ui::List_Expenditures_form *ui;
};

#endif // LIST_EXPENDITURES_FORM_H
