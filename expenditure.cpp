#include "expenditure.h"

Expenditure::Expenditure()
{

}

Expenditure::Expenditure(QString name, QString itemType, QString amountDescription, uint value, uint amount, uint year, uint month, uint day)
{
    this->name = name;
    this->itemType = itemType;
    this->amountDescription = amountDescription;
    this->value = value;
    this->amount = amount;
    this->year = year;
    this->month = month;
    this->day = day;
}

const QString &Expenditure::getName() const
{
    return name;
}

void Expenditure::setName(const QString &newName)
{
    name = newName;
}

const QString &Expenditure::getItemType() const
{
    return itemType;
}

void Expenditure::setItemType(const QString &newItemType)
{
    itemType = newItemType;
}

const QString &Expenditure::getAmountDescription() const
{
    return amountDescription;
}

void Expenditure::setAmountDescription(const QString &newAmountDescription)
{
    amountDescription = newAmountDescription;
}

uint Expenditure::getValue() const
{
    return value;
}

void Expenditure::setValue(uint newValue)
{
    value = newValue;
}

uint Expenditure::getAmount() const
{
    return amount;
}

void Expenditure::setAmount(uint newAmount)
{
    amount = newAmount;
}

uint Expenditure::getYear() const
{
    return year;
}

void Expenditure::setYear(uint newYear)
{
    year = newYear;
}

uint Expenditure::getMonth() const
{
    return month;
}

void Expenditure::setMonth(uint newMonth)
{
    month = newMonth;
}

uint Expenditure::getDay() const
{
    return day;
}

void Expenditure::setDay(uint newDay)
{
    day = newDay;
}
