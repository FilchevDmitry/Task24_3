#include<iostream>
#include<ctime>
#include<string>
#include<iomanip>
#include "windows.h"
#pragma warning(disable : 4996)
int main()
{
	std::cout << "Enter the time MM:SS ";
	std::time_t t = std::time(nullptr);
	std::tm end = *std::localtime(&t);
	std::cin >> std::get_time(&end, "%M:%S");
	std::time_t ou = std::mktime(&end);
	while (true)
	{
		std::time_t d = std::time(nullptr);
		std::tm local = *std::localtime(&d);
		std::time_t f = std::difftime(ou, d);
		std::tm tm = *std::localtime(&f);
		Sleep(1000);
		std::cout << std::put_time(&tm, "%M:%S") << std::endl;
		if (f == 0) break;
	}
	std::cout << "DING! DING! DING!" << std::endl;
}
