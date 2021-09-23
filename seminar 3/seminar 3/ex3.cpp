#include "function_set.hpp"

void f3()
{
	std::vector <double > list;
	auto n = 30U;
	for (double i = 0.0; i < n; i++)
	{
		list.push_back(i);
	}
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(list.begin(), list.end(), g);;

	auto direct_sort = [](double x, double y) {return x < y; };
	auto reverse_sort = [](double x, double y) {return x < y; };

	std::cout << "inputlist: ";
	for (auto i : list)
		std::cout << i << ' ';
	std::cout << '\n';

	std::sort(std::begin(list), std::end(list), direct_sort);

	std::cout << "direct_sort: ";
	for (auto i : list)
		std::cout << i << ' ';
	std::cout << '\n';

	std::sort(std::begin(list), std::end(list), reverse_sort);

	std::cout << "reverse_sort: ";
	for (auto i : list)
		std::cout << i << ' ';
	std::cout << '\n';
}