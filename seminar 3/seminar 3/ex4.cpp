#include "function_set.hpp"


void f4()
{	
	double x = 10.0;
	double y = 3.14;
	std::vector <std::function <double(double, double)>> lambda_list =
	{
		[](double x, double y) { return x + y; },
		[](double x, double y) { return x - y; },
		[](double x, double y) { return y - x; },
		[](double x, double y) { return x * y; },
		[](double x, double y) { return x / y; },
		[](double x, double y) { return y / x; },
		[](double x, double y) { return std::abs(x - y); },
		[](double x, double y) { return std::abs(x * y); },
		[](double x, double y) { return std::pow(x,y); },
		[](double x, double y) { return std::pow(y,x); },
		[](double x, double y) { return std::log(x) / log(y); },
		[](double x, double y) { return std::log(y) / log(x); },
	};

	std::cout << "start calculate\n" << "x =" << x << "\ty = " << y << '\n';
	for (auto i : lambda_list)
	{
		std::cout << calculate(x,y,i) << '\n';
	}
}
double calculate(double x, double y, std::function <double(double, double)> f)
{
	return f(x, y);
}