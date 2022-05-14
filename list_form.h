#ifndef LIST_FORM_H
#define LIST_FORM_H

#include <QWidget>

namespace Ui {
class List_form;
}

class List_form : public QWidget
{
    Q_OBJECT

public:
    explicit List_form(QWidget *parent = nullptr);
    ~List_form();

private:
    Ui::List_form *ui;
};

#endif // LIST_FORM_H
