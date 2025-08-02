#include "financialManagement.h"
#include "Utils.h"
#include <fstream>
#include <ostream>
#include <iomanip>
#include <transaction.h>
#include <memory>
#include <iostream>
#include <iomanip>
using namespace Utils;

financialManagement::financialManagement() : nextId(1) {}

void financialManagement::addTransaction()
{
    std::cout << "Thêm giao dịch mới" <<std::endl;
    double amount = readDouble("Nhập số tiền: ");
    std::string date = readDate("Nhập ngày (YYYY-MM-DD): ");
    std::string category = readString("Nhập danh mục: ");
    std::string node = readString("Thêm ghi chú: ");

    int typeChoice = readInt("Loại giao dịch: (1: thu , 2: chi)");

    TransactionType type;

    if(typeChoice == 1)
    {
        type = TransactionType::INCOME;
    }
    else if (typeChoice == 2)
    {
        type = TransactionType::EXPENSE;
    }
    else
    {
        std::cout<<"Loại giao dich không hợp lệ \n";
        return;
    }

    std::shared_ptr<transaction> newTrans = std::make_shared <transaction> (nextId++, amount, date, category, type, node);
    transactions.push_back(newTrans);

    std::cout << "Giao dịch đã được thêm thành công !!!";

}

void financialManagement::listTransactions() const
{
    for( const auto& f : transactions)
    {
        f->print();
    }
}

double financialManagement::calculateBalance() const
{
    double total = 0.0;
    for ( const auto & f : transactions)
    
    {
        if ( f->getType() == TransactionType::INCOME)
        {
        total += f->getAmount();
        }
        else
        {
        total -= f->getAmount();
        }
    }
    return total;

}

void financialManagement::savetoFile(const std::string& filename) const
{
    std::ofstream file(filename);
    if(!file.is_open())
    {
        return;
    }
    for( const auto& f : transactions)
    {
        file << f->getId() << "," 
        << f->getAmount() << "," 
        <<f->getCategory() <<"," 
        << f->getDate()<< "," 
        << f->getNode()<<","
        << static_cast<int>(f->getType()) << "\n";
    }
    file.close();


}

void financialManagement::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if(! file.is_open())
    {
        return;
    }

    transactions.clear();
    nextId = 1;

    std::string line;
    while (std::getline(file, line)) 
    {
        std::stringstream ss(line);
        std::string idStr, amountStr, date, category, typeStr, note;

        std::getline(ss, idStr, ',');
        std::getline(ss, amountStr, ',');
        std::getline(ss, date, ',');
        std::getline(ss, category, ',');
        std::getline(ss, typeStr, ',');
        std::getline(ss, note); 

        int id = std::stoi(idStr);
        double amount = std::stod(amountStr);
        TransactionType type = static_cast<TransactionType>(std::stoi(typeStr));

        auto t = std::make_shared<transaction>(id, amount, date, category, type, note);
        transactions.push_back(t);
        nextId = std::max(nextId, id + 1);
    }

    file.close();


}