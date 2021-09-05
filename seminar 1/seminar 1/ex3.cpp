#include<iostream>
#include<iomanip>
#include<limits>
#include<cmath>

int main()
{
	std::cout << "solving the quadratic equation\n";

	double D, a, b, c;
	const double epsilon = std::numeric_limits<double>::epsilon();

	std::cout << "factors A = ";
	std::cin >> a;

	std::cout << "factors B = ";
	std::cin >> b;

	std::cout << "factors C = ";
	std::cin >> c;

	D = std::pow(b, 2) - 4*a*c;

	std::cout << '\n' << "*************** OUTPUT ***************" << "\n\n";
	std::cout.precision(8);

	if (std::abs(D) < epsilon)
	{
		std::cout << "the equation has one solution\n" << std::fixed << std::showpos << (-b / (2 * a));
	}
	else if (D < 0)
	{
		std::cout << "the equation has no solution";
	}
	else
	{
		std::cout << "the equation has two solution";
		std::cout << "\nx1 = " << std::fixed << std::showpos << ((-b - std::sqrt(D)) / (2 * a));
		std::cout << "\nx2 = " << std::fixed << std::showpos << ((-b + std::sqrt(D)) / (2 * a));
	}
	std::cout << "\n\n";

	return 0;
}