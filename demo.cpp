
#include <iostream>

#include "ini.hpp"

int main()
{

    std::string path = "..//param.ini";
    int age = GetParam<int>("Setting","age",path);
    
    std::string str = GetParam<std::string>("Param","word",path);

    std::cout << age << "\n";
    std::cout << str << "\n";
    return 0;
}


