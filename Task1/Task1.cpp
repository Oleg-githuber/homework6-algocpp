// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

int simple_string_hash(std::string str);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str{};
    while (str != "exit")
    {
        std::cout << "Введите строку: ";
        std::cin >> str;
        std::cout << "Наивный хэш строки " << str << " = " << simple_string_hash(str) << std::endl;
    }

    return EXIT_SUCCESS;
}

// Простое хеширование строки
int simple_string_hash(std::string str)
{
    unsigned long long length{ str.length()};
    int hashCode{};
    for (unsigned long long i{}; i < length; ++i)
    {
        hashCode += str[i];
    }
    return hashCode;
}