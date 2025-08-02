#include "transaction.h"
#include <iostream>

transaction::transaction(int id, double amount, std::string date, std::string category, TransactionType type, std::string node)
: id(id), amount(amount), date(date), category(category), type(type), node(node) {}

void transaction::setId(int id)
{
    this->id = id;
}

int transaction::getId() const
{
    return id;
}

void transaction::setAmount(double amount)
{
    this->amount = amount;
}

double transaction::getAmount() const
{
    return amount;
}

void transaction::setDate(std::string& date)
{
    this->date = date;
}

std::string transaction::getDate() const
{
    return date;
}

void transaction::setCategory(std::string category )
{
    this->category = category;
}

std::string transaction::getCategory() const
{
    return category;
}

void transaction::setNode(std::string node)
{
    this->node = node;
}

std::string transaction::getNode() const
{
    return node;
}

void transaction::setType(TransactionType& type)
{
    this->type = type;
}
TransactionType transaction::getType() const
{
    return type;
}

void transaction::print() const
{
        std::cout << "[" << (type == TransactionType::INCOME ? "Income" : "Expense") << "] "
              << date << " | " << category << " | $" << amount
              << " | " << node << " (ID: " << id << ")\n";
}