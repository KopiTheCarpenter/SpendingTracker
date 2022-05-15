#ifndef EXPENDITURE_H
#define EXPENDITURE_H

#include <QString>



class Expenditure
{
private:
    QString name,itemType, amountDescription;
    uint value, amount;
public:
    Expenditure();
    Expenditure(QString name, QString itemType, QString amountDescription, uint value, uint amount);

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

    QString toInstertString();
};

#endif // EXPENDITURE_H
