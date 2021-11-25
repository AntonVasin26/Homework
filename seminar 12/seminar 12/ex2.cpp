#include <iostream>

template <std::size_t n>
struct Fibonachi
{
	static inline const int value = Fibonachi<n - 1>::value + Fibonachi<n - 2>::value;
};

template <>
struct Fibonachi<1>
{
	static inline const int value = 1;
};

template <>
struct Fibonachi<2>
{
	static inline const int value = 1;
};

template <std::size_t n>
inline const int Fibonachi_v = Fibonachi<n>::value;

int main()
{
	std::cout << Fibonachi_v<4>;
}