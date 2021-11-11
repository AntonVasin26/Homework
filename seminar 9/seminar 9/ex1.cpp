#include "merge_sort.hpp"

int main()
{
    int array[10] = { -1, 0, -4, 0, 2, 7, 3, 10, -12, 2 };
    auto direct_sort = [](int x, int y) {return x < y; };
    dyn_and_st_sort(array, direct_sort);
    for (auto i = 0U; i < 10; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';

    std::size_t N = 3;
    int* b = new int[N];
    b[0] = -100; b[1] = 0; b[2] = 1;

    dyn_and_st_sort<int>(b, 3, direct_sort);

    for (auto i = 0U; i < N; ++i)
        std::cout << b[i] << " ";

    delete[] b;
}