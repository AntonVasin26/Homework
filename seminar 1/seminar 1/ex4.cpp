#include<iostream>

int main()
{
	double a, b;

	std::cout << "variable 1 = ";
	std::cin >> a;
	std::cout << "variable 2 = ";
	std::cin >> b;

	a = a + b;
	b = a - b;
	a = a - b;

	std::cout << "variable 1 = " << a << '\n';
	std::cout << "variable 2 = " << b << '\n';
	std::cout << "\n\n";
	return 0;
}

