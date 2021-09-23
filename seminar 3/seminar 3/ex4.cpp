#include "function_set.hpp"


void f4()
{	
	double x = 10.0;
	double y = 3.14;
	std::vector <std::function <double(double, double)>> lambda_list =
	{
		[](auto x, auto y) { return x + y; },
		[](auto x, auto y) { return x - y; },
		[](auto x, auto y) { return y - x; },
		[](auto x, auto y) { return x * y; },
		[](auto x, auto y) { return x / y; },
		[](auto x, auto y) { return y / x; },
		[](auto x, auto y) { return std::abs(x - y); },
		[](auto x, auto y) { return std::abs(x * y); },
		[](auto x, auto y) { return std::pow(x,y); },
		[](auto x, auto y) { return std::pow(y,x); },
		[](auto x, auto y) { return std::log(x) / log(y); },
		[](auto x, auto y) { return std::log(y) / log(x); },
	};

	std::cout << "\nstart calculate\n" << "x =" << x << "\ty = " << y << '\n';
	for (auto i : lambda_list)
	{
		std::cout << calculate(x,y,i) << '\n';
	}
}
double calculate(double x, double y, std::function <double(double, double)> f)
{
	return f(x, y);
}