#include "list_function.hpp"



struct Time_date
{
	Time_date(int millisecond = 0, int second = 0, int minutå = 0, int hour = 0, int day = 1, Month month = Month::January, int year = 2000) :
		millisecond(millisecond), second(second), minute(minutå), hour(hour), day(day), month(month), year(year)
	{
		if (millisecond >= 1000 || millisecond < 0 )
			std::cout << ("\nSecond must be in range [0; 1000)\n");

		if (second >= 60 || second < 0)
			std::cout << ("\nSecond must be in range [0; 60)\n");

		if (minute >= 60 || minute < 0)
			std::cout << ("\nMinute must be in range [0; 60)\n");

		if (hour >= 24)
			std::cout << ("\nHour must be in range [0; 24)\n");

		if (day > days_in_month(month, year) || day == 0)
			std::cout << ("\nIncorrect day\n");

		if (year > 4047)
			std::cout << "\nYear be in range [0; 4047)\n";
	}

	Month month : 4;
	unsigned year : 12;
	unsigned day : 5;
	unsigned hour : 5;
	unsigned minute : 6;
	unsigned second : 6;
	unsigned millisecond : 10;

	
	void print()
	{
		std::cout << "time: " << millisecond << "ms :" << second << "s : " << minute << "min :" << hour << "hors \t";
		std::cout << "Date: " << day << "." << int(month) <<  '.' << year << (leap_year(year) ? "L.Y\n" : "U.Y\n");
	}
};



void ex3()
{
	std::cout << "\nex3 start\n\n";
	Time_date day1(332, 54, 32, 22, 31, Month::Jule, 2021);
	Time_date day2(456, 44, 38, 21, 29, Month::February, 2020);
	day1.print();
	day2.print();
	std::cout << "\nex3 end\n\n";
}
