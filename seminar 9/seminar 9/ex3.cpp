#include <functional>
#include <iostream>

//namespace tmp
//{
//	template< typename T, typename Func >
//	void quick_sort(T* arr, int left, int right, Func Compatator)
//	{
//		if (right - left < 1) return;
//
//		int k = left;
//		for (auto i = left; i < right; i++)
//		{
//			if (Compatator(arr[i], arr[right]))
//			{
//				std::swap(arr[i], arr[k]);
//				k++;
//			}
//		}
//		std::swap(arr[k], arr[right]);
//		quick_sort(arr, left, k - 1, Compatator);
//		quick_sort(arr, k + 1, right, Compatator);
//	}
//
//
//	template< typename T, typename Func = std::less_equal <T> >
//	void sort(T* arr, std::size_t N, Func Compatator = std::less_equal< T >{})
//	{
//		quick_sort(arr, 0, N - 1, Compatator);
//	}
//
//	template< typename T, std::size_t N, typename Func = std::less_equal <T> >
//	void sort(T(&arr)[N], Func Compatator = std::less_equal< T >{})
//	{
//		quick_sort(arr, 0, N - 1, Compatator);
//	}
//}
//
//
//
//int main()
//{
//	int arr1[7] = { 4, 5, 6, 2, 0, 1, 3 };
//
//	std::size_t n = 6;
//	double* arr2 = new double[n] { 3.1, 4.1, 5.9, 2.6, 5.3, 5.9 };
//
//	tmp::sort(arr1);
//	tmp::sort(arr2, n, [](auto left, auto right) { return left >= right; });
//
//	for (auto i : arr1)
//		std::cout << i << " ";
//	std::cout << std::endl;
//
//	for (auto i = 0U; i < n; i++)
//		std::cout << arr2[i] << " ";
//	std::cout << std::endl;
//
//	delete[] arr2;
//	return EXIT_SUCCESS;
//}