#include "function_set.hpp"

void f1()
{
	std::cout << "fibonachi(13) = " << fibonachi(13) << "\n\n";
}


int fibonachi(int n)
{
	if (n > 2)
	{
		return fibonachi(n - 1) + fibonachi(n - 2);
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

