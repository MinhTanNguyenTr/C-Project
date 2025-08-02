#ifndef FINANCIALMANAGEMENT_H
#define FINANCIALMANAGEMENT_H
#include "transaction.h"
#include <iostream>
#include "category.h"
#include <vector>
#include <memory>
class financialManagement
{
    public:
    financialManagement();
    void addTransaction();
    void listTransactions() const;
    double calculateBalance() const;
    void savetoFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    private:
    std::vector< std::shared_ptr<transaction>> transactions;
    int nextId;
};

#endif