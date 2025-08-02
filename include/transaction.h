#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <iostream>

enum class TransactionType : int 
{
    INCOME =0,
    EXPENSE
};

class transaction
{
    public:
    void setId(int id);
    int getId() const;
    void setAmount(double amount);
    double getAmount() const;
    void setDate(std::string& date);
    std::string getDate() const;
    void setCategory(std::string category);
    std::string getCategory() const;
    void setNode(std::string node);
    std::string getNode() const;
    void setType(TransactionType& type);
    TransactionType getType() const;
    transaction(int id, double amount, std::string date, std::string category, TransactionType type, std::string node);
    transaction() = default;
    void print() const;
    private:
    int id;
    double amount;
    std::string date;
    std::string category;
    std::string node;
    TransactionType type;
};


#endif // TRANSACTION_H