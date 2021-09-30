#include "list_function.hpp"


unsigned days_in_month(Month month, int year)
{
	switch (month)
	{
	case Month::February:
		return (leap_year(year)) ? 29U : 28U;
		break;
	case Month::April:
	case Month::June:
	case Month::September:
	case Month::November:
		return 30;
	default:
		return 31;
	}
}

bool leap_year(int year)
{
	return (year % 400 == 0) ? true : (year % 100 == 0) ? false : (year % 4 == 0) ? true : false;
}

void ex4()
{
	std::cout << "\nex4 start\n\n";
	std::cout << days_in_month(Month::February, 1998) << " February 1998" << '\n';
	std::cout << days_in_month(Month::February, 2008) << " February 2008" << '\n';

	std::cout << days_in_month(Month::September, 2000) << " September 2000:" << '\n';
	std::cout << "\nex4 end\n";
}