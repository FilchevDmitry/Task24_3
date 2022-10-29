#include<iostream>
#include<ctime>
#include<iomanip>
#pragma warning(disable : 4996)
int main()
{
	std::cout << "Enter the time MM:SS ";
	std::time_t t = std::time(nullptr);
	std::tm temp = *std::localtime(&t);
	std::cin >> std::get_time(&temp, "%M:%S");
	std::time_t out = std::mktime(&temp);
	while (true)
	{	
		std::time_t start = std::time(nullptr);
		std::time_t end= std::time(nullptr);
		std::time_t delta = std::difftime(out, start);
		std::tm tm = *std::localtime(&delta);
		while (end<start+1)
		{
			end= std::time(nullptr);
		}
		std::cout << std::put_time(&tm, "%M:%S") << std::endl;
		if (delta == 0) break;
	}
	std::cout << "DING! DING! DING!" << std::endl;
}
