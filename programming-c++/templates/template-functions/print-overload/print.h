#pragma once

#include <iostream>

inline void print(int value)
{
    std::cout << value << std::endl;
}

inline void print(double value)
{
    std::cout << value << std::endl;
}


inline void print(const std::string &value)
{
    std::cout << value << std::endl;
}


