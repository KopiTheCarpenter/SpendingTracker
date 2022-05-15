#ifndef EXPENDITURE_H
#define EXPENDITURE_H

#include <QString>



class Expenditure
{
private:
    QString name,itemType, amountDescription;
    uint value, amount,year,month,day;
public:
    Expenditure();
    Expenditure(QString name, QString itemType, QString amountDescription, uint value, uint amount, uint year, uint month, uint day);

    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getItemType() const;
    void setItemType(const QString &newItemType);
    const QString &getAmountDescription() const;
    void setAmountDescription(const QString &newAmountDescription);
    uint getValue() const;
    void setValue(uint newValue);
    uint getAmount() const;
    void setAmount(uint newAmount);
    uint getYear() const;
    void setYear(uint newYear);
    uint getMonth() const;
    void setMonth(uint newMonth);
    uint getDay() const;
    void setDay(uint newDay);
};

#endif // EXPENDITURE_H
