#include "Utils.h"
#include <iostream>

namespace Utils {

    double readDouble(const std::string& prompt)
    {
        double input;
        std::cout<<prompt;
        std::cin>>input;
        return input;
    }

    std::string readString(const std::string& prompt)
    {
        std::string value;
        std::cout<<prompt;
        std::getline(std::cin, value);
        return value;
    }

    int readInt(const std::string& prompt)
    {
        int input;
        std::cout<<prompt;
        std::cin>>input;
        return input;
    }

    std::string readDate(const std::string& prompt)
    {
        std::string date;
        std::cout<<prompt;
        std::getline(std::cin, date);
        return date;
    }

    void pauseScreen()
    {
        std::cout<<"\nNhấn enter để tiếp tục ... " <<std::endl;
    }


}