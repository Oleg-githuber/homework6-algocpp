// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <math.h>

unsigned long long enterNumber(std::string str, bool mustBeSimple);
unsigned long long real_string_hash(unsigned long long p, unsigned long long n, std::string str);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned long long p = enterNumber("Введите p: ", true);
	unsigned long long n = enterNumber("Введите n: ", false);
	std::string str{};
	while (str != "exit")
	{
		std::cout << "\nВведите строку: ";
		std::cin >> str;
		std::cout << "\nХэш строки " << str << " = " << real_string_hash(p, n, str) << '\n';
	}
	

	return EXIT_SUCCESS;
}

// Проверка, простое ли число
bool isSimple(unsigned long long p)
{
	if (p <= 0)
	{
		return false;
	}
	for (unsigned long long i{2}; i < p; ++i)
	{
		if (p % i == 0)
		{
			return false;
		}
	}
	return true;
}

// Ввод числа с клавиатуры
unsigned long long enterNumber(std::string str, bool mustBeSimple)
{
	while (true)
	{
		std::cout << '\n' << str;
		unsigned long long number{};
		if (std::cin >> number)
		{
			if (!mustBeSimple)
			{
				return number;
			}
			else
			{
				if (isSimple(number))
				{
					return number;
				}
				else
				{
					std::cout << "\nЧисло должно быть простым!" << std::endl;
				}
			}
		}
		else
		{
			std::cout << "\nВы ввели некорректное значение!" << std::endl;
		}
		std::cin.clear();
		std::cin.ignore();
	}
}

// Хеширование
unsigned long long real_string_hash(unsigned long long p, unsigned long long n, std::string str)
{
	unsigned long long hashCode{};
	unsigned long long length{ str.length() };
	for (unsigned long long i{}; i < length; ++i)
	{
		hashCode += (str[i] * static_cast<unsigned long long>(pow(p, i)));
	}
	return hashCode % n;
}