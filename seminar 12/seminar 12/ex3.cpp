#include <iostream>
#include <numeric>

constexpr double e(double epsilon = 1.0e-7)
{
	double ans = 1.0;
	long factorial = 1.0;
	int cnt = 2;
	while (1.0 / factorial - epsilon > std::numeric_limits<double>::epsilon())
	{
		ans += 1.0 / factorial;
		factorial *= cnt++;
	}
	return ans;
}

int main()
{
	std::cout << e();
}