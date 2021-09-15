#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::cout << "program start\n\n";
	std::vector <double> inV;
	inV = { 2.3, 4.3, 1.2, 1.1, 8.3, 2.2, 4.1, 3.2 };
	for (auto i = 1U; i < inV.size(); ++i)
	{
		for (auto j = i; j > 0; --j)
		{
			if (inV[j - 1] > inV[j])
			{
				std::swap(inV[j-1], inV[j]);
			}
		}
	}


	for (auto i = 0U; i < inV.size(); ++i)
	{
		std::cout << inV[i] << "; ";
	}

	return 0;
}