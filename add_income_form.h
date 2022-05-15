#ifndef ADD_INCOME_FORM_H
#define ADD_INCOME_FORM_H

#include <QDialog>

namespace Ui {
class Add_Income_Form;
}

class Add_Income_Form : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Income_Form(QWidget *parent = nullptr);
    ~Add_Income_Form();

private:
    Ui::Add_Income_Form *ui;
};

#endif // ADD_INCOME_FORM_H
