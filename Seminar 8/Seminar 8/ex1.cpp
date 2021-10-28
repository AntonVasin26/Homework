#include "Header.hpp"

using namespace std;

enum class MyError
{
	E_a_violates_the_triangle_rule,
	E_b_violates_the_triangle_rule,
	E_c_violates_the_triangle_rule,
};


MyError get_random_error()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	return MyError(gen()%5);
}

std::variant <MyError, int> f1(int a, int b, int c)
{
	if (a > b + c)
	{
		return MyError(0);
	}
	if (b > a + c)
	{
		return MyError(1);
	}
	if (c > a + c)
	{
		return MyError(2);
	}
	return a + b + c;
}

int f2(int a, int b, int c)
{
	if (a > b + c)
	{
		errno = static_cast<int>(MyError(0));
	}
	if (b > a + c)
	{
		errno = static_cast<int>(MyError(1));
	}
	if (c > a + c)
	{
		errno = static_cast<int>(MyError(2));
	}
	if (errno)
		std::cout << "\nfind error: " << errno << '\n';
	return a + b + c;
}



void ex1()
{
	std::cout << "\nex1 start\n";
	std::random_device rd;
	std::mt19937 gen(rd());
	
	for (int i = 0; i < 10; i++)
	{
		variant <MyError, int> perimetr = f1(gen()%10, gen()%10, gen()%10);
		if (std::holds_alternative<MyError>(perimetr))
		{
			int e = static_cast<int>(get<MyError>(perimetr));
			std::cout << "\nfind error:" << e << "\n";
		}
		else
		{
			int p = get<int>(perimetr);
			std::cout << "\nperimetr = " << p << '\n';
		}
	}
	std::cout << "\n\n with errno\n\n";
	for (int i = 0; i < 10; i++)
	{
		int p = f2(gen() % 10, gen() % 10, gen() % 10);
		std::cout << p << '\n';
	}
}


