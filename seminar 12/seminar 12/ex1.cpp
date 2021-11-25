#include <iostream>

template <int power, int index>
struct Binom_c
{
	static const int value = Binom_c<power-1, index - 1>::value + Binom_c <power-1, index>::value;
};

template <int power>
struct Binom_c < power, 0 >
{
	static const int value = 1;
};

template <int power>
struct Binom_c < power, power >
{
	static const int value = 1;
};

int main()
{
	constexpr int ans1 = Binom_c< 4, 2>::value;
	std::cout << ans1;
}