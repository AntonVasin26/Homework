#include "Header.hpp"


int f3(int a, int b, int c)
{
	if (a > b + c)
	{
		throw std::range_error("a > b + c");
	}
	if (b > a + c)
	{
		throw std::range_error("b > a + c");
	}
	if (c > a + c)
	{
		throw std::range_error("c > a + b");
	}
	return a + b + c;
}

void f4(int a[] , std::size_t l, int b)
{
	if (l > sizeof(a) / sizeof(a[0]))
		throw std::length_error("index out of range");
	a[l] = b;
}


int f5(int x, int y)
{
	int m = std::numeric_limits<int>::max();
	if (m / x < y)
		throw std::overflow_error("|x*y| > max(int)");
	return x * y;
}

int f6(double x)
{
	if (abs(x) < std::numeric_limits<double>::epsilon())
		throw std::domain_error("1/x Undefined at zero");
	double y = 1 / x;
	return (y);
}

double f7(double x, double y)
{
	if (x * y < 0.0)
		throw std::logic_error("the root of negative numbers");
	return pow(x * y, 0.5);
}

void ex2()
{
	std::cout << "\nex2 start\n";
	try
	{
		f3(10, 4, 4);
	}
	catch (const std::range_error& e)
	{
		std::cout << "\nf3 found error\n";
	}
	try
	{
		int* a = new int[5];
		f4(a, 7, 12);
	}
	catch (const std::length_error& e)
	{
		std::cout << "\nf4 found error\n";
	}
	try
	{
		f5(10000034, 2000334000);
	}
	catch (const std::overflow_error& e)
	{
		std::cout << "\nf5 found error\n";
	}
	try
	{
		f6(0.0000000000000000000000000000000000000000000000000000000000000000001);
	}
	catch (const std::domain_error& e)
	{
		std::cout << "\nf6 found error\n";
	}
	try
	{
		f7(2.0, -2.0);
	}
	catch (const std::logic_error& e)
	{
		std::cout << "\nf7 found error\n";
	}
}