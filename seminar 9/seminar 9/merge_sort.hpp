#pragma once
#include <iostream>
#include <vector>

template <typename T, typename F>
void merge(T* array, std::size_t begin, std::size_t end, F comp)
{
    auto length = end - begin;
    auto mid = (begin + end) / 2;
    auto i = begin;
    auto j = mid + 1;
    std::vector<T> merged_array;
    //T* merged_array = new T[length];
    for (auto step = 0; step < length + 1; step++)
    {
        if ((j > end) || ((i <= mid) && comp(array[i], array[j])))
        {
            merged_array.push_back(array[i]);
           //merged_array[step] = array[i];
            i++;
        }
        else
        {
            merged_array.push_back(array[j]);
            //merged_array[step] = array[j];
            j++;
        }
    }
    for (auto step = 0; step < length + 1; step++)
    {
        array[begin + step] = merged_array[step];
    }
    //delete[] merged_array;// - I don't understand why it doesn't work with this line
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

template< typename T>
void dyn_and_st_sort(T* arr, std::size_t N)
{
    merge_sort(arr, 0, N - 1, std::less<>{});
}

template< typename T, std::size_t N>
void dyn_and_st_sort(T(&arr)[N])
{
    merge_sort(arr, 0, N - 1, std::less<>{});
}


