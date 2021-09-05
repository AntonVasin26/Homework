#include<iostream>
#include <iomanip>

int main()
{
	double values;
	char format1, format2;
	std::cout << "temperatures" << '\n';
	std::cout << '\n' << "C - Celsius" << '\n' << "K - Kelvin" << '\n' << "F - Fahrengate" << '\n';
	std::cout << "select the input format: ";
	std::cout.precision(1);
	std::cin >> format1;
	std::cout << "values: ";
	std::cin >> values;
	std::cout << "select the output format: ";
	std::cin >> format2;
	switch (format1)
	{
		case 'C':
		{
			switch (format2)
			{
			case 'K':
				values = values + 273;
				break;
			case 'F':
				values = values * 9 / 5 + 32;
				break;
			}
			break;
		}
		case 'K':
		{
			switch (format2)
			{
			case 'C':
				values = values - 273;
				break;
			case 'F':
				values = (values - 273) * 9 / 5 + 32;
				break;
			}
			break;
		}
		case 'F':
		{
			switch (format2)
			{
			case 'C':
				values = (values - 32) * 5 / 9;
				break;
			case 'K':
				values = (values - 32) * 5 / 9 + 273;
				break;
			}
			break;
		}
	}
	std::cout << std::fixed << std::showpos << values;
	std::cout << "\n\n";
	return 0;
}