#ifndef UTILS_H
#define UTILS_H
#include "transaction.h"
#include <iostream>
#include "category.h"
#include <string>
namespace Utils
{
    std::string readString(const std::string& prompt);
    double readDouble(const std::string& prompt);
    int readInt(const std::string& prompt);
    std::string readDate(const std::string& prompt);
    void pauseScreen();
}

#endif