#include "Header.hpp"

template <typename ... T >
auto size_of_Poket1(T && ... args)
{
	return (... + sizeof(args));
}


int size_of_Poket2() { return 0;}

template <typename T, typename ... Types>
int size_of_Poket2(T && arg, Types && ... args)
{
	return sizeof(arg) + size_of_Poket2(args...);
}

void ex1()
{
	std::tuple <int, std::string> t1(8, "abcd");
	std::cout << "size_of_Poket1(with convolution) " << size_of_Poket1(1, 1.111, t1) << '\n';
	std::cout << "size_of_Poket2(without convolution) " << size_of_Poket2(1, 1.111, t1) << '\n';
}