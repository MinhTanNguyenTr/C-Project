#include "category.h"
#include <iostream>
#include <string>

category::category(std::string& name, CategoryType type)
    : name(name), type(type) {}

std::string category::getName() const
{
    return name;
}

CategoryType category::getType() const
{
    return type;
}

