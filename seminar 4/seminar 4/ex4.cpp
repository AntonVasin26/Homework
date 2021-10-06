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
		return 30U;
	case Month::January:
	case Month::March:
	case Month::May:
	case Month::Jule:
	case Month::August:
	case Month::October:
	case Month::December:
		return 31U;
	default:
		std::cout << "out of range";
		return 0;
	}
}

bool leap_year(int year)
{
	return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

void ex4()
{
	std::cout << "\nex4 start\n\n";
	std::cout << days_in_month(Month::February, 1998) << " February 1998" << '\n';
	std::cout << days_in_month(Month::February, 2008) << " February 2008" << '\n';
	std::cout << days_in_month(Month::September, 2000) << " September 2000:" << '\n';
	std::cout << "\nex4 end\n";
}