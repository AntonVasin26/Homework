#include "function_set.hpp"

void f3()
{
	std::vector <double> list = { 45,34,55,2,3,45,343,34,22,4,1,223,5,89,76 };

	auto direct_sort = [](double x, double y) {return x < y; };
	auto reverse_sort = [](double x, double y) {return x < y; };

	std::cout << "inputlist: ";
	for (auto i : list)
		std::cout << i << ' ';
	std::cout << '\n';

	std::sort(list.begin(), list.end(), direct_sort);

	std::cout << "direct_sort: ";
	for (auto i : list)
		std::cout << i << ' ';
	std::cout << '\n';

	std::sort(list.begin(), list.end(), reverse_sort);

	std::cout << "reverse_sort: ";
	for (auto i : list)
		std::cout << i << ' ';
	std::cout << '\n';
}