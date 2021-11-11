#include "vector.hpp"

int main()
{
	My_space::Vector<int> vec(5, 1);

	vec.push_back(2);
	for (auto i = 0U; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;

	My_space::swap(vec[0], vec[vec.size() - 1]);
	vec.pop_back();
	for (auto i = 0U; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ' ';
	}

	std::cout << std::endl;

}