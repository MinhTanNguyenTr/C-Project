#include "financialManagement.h"
#include "Utils.h"
#include <fstream>
#include <ostream>
#include <iomanip>
#include <transaction.h>

using namespace Utils;

financialManagement::financialManagement() : nextId(1) {}

void financialManagement::addTransaction()
{
    double amount = readDouble("Enter transaction amount: ");
    std::string date = readDate("Enter transaction date (YYYY-MM-DD): ");
    std::string category = readString("Enter transaction category: ");
    std::string node = readString("Enter transaction node: ");
    
}

void financialManagement::listTransactions() const
{

}

double financialManagement::calculateBalance() const
{
}

void financialManagement::savetoFile(const std::string& filename) const
{
}

void financialManagement::loadFromFile(const std::string& filename)
{
}