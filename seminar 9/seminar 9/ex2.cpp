#include "vector.hpp"

int main()
{
	My_space::Vector<int> vec1(5, 1);

	vec1.push_back(2);
	for (auto i = 0U; i < vec1.size(); ++i)
	{
		std::cout << vec1[i] << ' ';
	}
	std::cout << std::endl;

	vec1.pop_back();
	for (auto i = 0U; i < vec1.size(); ++i)
	{
		std::cout << vec1[i] << ' ';
	}
	std::cout << std::endl;

	My_space::Vector<int> vec2(3, 2);

	vec1.swap(vec2);
	for (auto i = 0U; i < vec1.size(); ++i)
	{
		std::cout << vec1[i] << ' ';
	}
}