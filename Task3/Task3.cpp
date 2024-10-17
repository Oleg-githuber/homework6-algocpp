// Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <math.h>

std::string enderSubstring(uint32_t length);
int64_t find_substring_light_rabin_karp(std::string str, std::string substr);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::string str{};
    std::cin >> str;
    std::string substr{};
    while (substr != "exit")
    {
        substr = enderSubstring(str.length());
        int64_t enterIndex{ find_substring_light_rabin_karp(str, substr) };
        if (enterIndex < 0)
        {
            std::cout << "Подстрока " << substr << " не найдена";
        }
        else
        {
            std::cout << "Подстрока " << substr << " найдена по индексу " << find_substring_light_rabin_karp(str, substr);
        }
    }

    return EXIT_SUCCESS;
}

// Ввод подстроки с проверкой длины
std::string enderSubstring(uint32_t length)
{
    std::string substr{};
    while (true)
    {
        std::cout << "\n\nВведите подстроку, которую нужно найти: ";
        std::cin >> substr;
        if (substr.length() <= length)
        {
            return substr;
        }
        std::cout << "\nДлина подстроки не может быть больше длины строки!\n";
        std::cin.clear();
        std::cin.ignore();
    }
}

// Простое примитивное хеширование
int simple_string_hash(std::string str)
{
    unsigned long long length{ str.length() };
    int hashCode{};
    for (unsigned long long i{}; i < length; ++i)
    {
        hashCode += str[i];
    }
    return hashCode;
}

// Вычисление хешкода начала строки
uint64_t calculateStartHashCode(std::string str, int lengthSubstr)
{
    uint64_t hashCode{};
    for (uint64_t i{}; i < lengthSubstr; ++i)
    {
        hashCode += str[i];
    }
    return hashCode;
}

// Сравнение части строки с подстрокой
bool compareStrings(std::string str, std::string substr, int64_t enterIndex)
{
    for (int64_t i{}; i < substr.length(); ++i)
    {
        if (substr[i] != str[i + enterIndex])
        {
            return false;
        }
    }
    return true;
}

// Нахождение индекса входа подстроки в строку
int64_t find_substring_light_rabin_karp(std::string str, std::string substr)
{
    int substrHashCode{ simple_string_hash(substr) };
    uint64_t startHashCode{ calculateStartHashCode(str, substr.length()) };
    for (uint64_t i{}; i <= str.length() - substr.length(); i++)
    {
        if (i > 0)
        {
            startHashCode = startHashCode - str[i - 1] + str[i + substr.length() - 1];
        }

        if (startHashCode == substrHashCode)
        {
            if (compareStrings(str, substr, i))
            {
                return i;
            }
        }
    }
    return -1;
}

