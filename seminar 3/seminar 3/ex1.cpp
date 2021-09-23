#include "function_set.hpp"

void f1()
{
	std::cout << "fibonachi start: ";
	for (auto i = 1; i < 15; i++) std::cout << fibonachi(i) << ' ';
	std::cout << "\n\n";
}


int fibonachi(int n)
{
	return (n > 2) ? (fibonachi(n - 1) + fibonachi(n - 2)) : n-1;
}

