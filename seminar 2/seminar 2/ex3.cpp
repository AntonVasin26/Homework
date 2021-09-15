#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::cout << "program start\n\n";
	std::vector <int> inV;
	inV = { 1,2,3,4,6,7,8,10,11,12,13,15,16,17,18,19,20 };
	int L=0, R=inV.size(), m, F;
	F = 1;
	while (L < R)
	{
		m = (L + (R - L) / 2);
		if (inV[m] > F)
		{
			R = m;
		}
		else
		{
			L = m + 1;
		}
	}
	if (inV[R - 1] == F)
	{
		std::cout << "number find: index = " << R - 1 << "\n\n";
	}
	else
		std::cout << "number unfind:\n\n";

	return 0;
}