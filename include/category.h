#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>
#include <iostream>

enum class CategoryType : int
{
    INCOME =0,
    EXPENSE
};

class category
{
    public:
    category(std::string& name, CategoryType type);
    std::string getName() const;
    CategoryType getType() const;
    private:
    std::string name;
    CategoryType type;
};

#endif