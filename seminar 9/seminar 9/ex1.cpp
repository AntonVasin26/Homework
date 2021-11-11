#include <iostream>



template <typename T, typename F>
void merge(T* array, std::size_t begin, std::size_t end, F comp)
{
	auto length = end - begin;
	auto mid = (begin + end) / 2;
	auto i = begin;
	auto j = mid + 1;
	T* merged_array = new T[length];
    for (auto step = 0; step < length + 1; step++)
    {
        if ((j > end) || ((i <= mid) && comp(array[i],array[j])))
        {
            merged_array[step] = array[i];
            i++;
        }
        else
        {
            merged_array[step] = array[j];
            j++;
        }
    }
    for (auto step = 0; step < length + 1; step++)
    {
        array[begin + step] = merged_array[step];
    }
    //delete[] merged_array; - I don't understand why it doesn't work with this line
}

template < typename T, typename F >
void merge_sort(T* array, std::size_t begin, std::size_t end, F comp)
{
    if (begin == end) return;
    auto mid = (begin + end) / 2;
    merge_sort(array, begin, mid, comp);
    merge_sort(array, mid + 1, end, comp);
    merge(array, begin, end, comp);
}


template< typename T, typename F>
void dyn_and_st_sort(T* arr, std::size_t N, F Comp)
{
    merge_sort(arr, 0, N - 1, Comp);
}

template< typename T, std::size_t N, typename F>
void dyn_and_st_sort(T(&arr)[N], F Comp)
{
    merge_sort(arr, 0, N - 1, Comp);
}


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