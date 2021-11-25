#include <iostream>
#include <array>

template <std::size_t n>
constexpr int simple()
{
	std::array<int, n> arr;
	int num = 3;
	arr[0] = 2;
	for (auto cnt = 1U; cnt < n; num += 2)
	{
		bool flag = true;
		for (auto i = 0U; (i < cnt) && (arr[i] * arr[i]) <= num; ++i)
		{
			if (num % arr[i] == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			arr[cnt++] = num;
		}
	}
	return arr[n - 1];
}

int main()
{
	constexpr auto answer = simple<5>;
	std::cout << answer();
}