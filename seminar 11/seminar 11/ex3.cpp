#include <iostream>
#include <type_traits>

namespace My
{
	template < typename T >
	struct decay
	{
		using type = T;
	};

	template < typename T >
	struct decay < T const >
	{
		using type = T;
	};

	template < typename T >
	struct decay < T& >
	{
		using type = T;
	};

	template < typename T >
	struct decay < const T& >
	{
		using type = T;
	};

	template < typename T >
	struct decay < T&& >
	{
		using type = T;
	};

	template < typename T >
	struct decay < const T&& >
	{
		using type = T;
	};

	template< typename T, typename ... Args >
	struct decay< T(Args...)>
	{
		using type = T;
	};

	template< typename T, typename ... Args >
	struct decay< const T(Args...) >
	{
		using type = T;
	};

	template< typename T, typename ... Args >
	struct decay< T(Args...)& >
	{
		using type = T;
	};

	template< typename T, typename ... Args >
	struct decay< const T(Args...)& >
	{
		using type = T;
	};

	template< typename T, typename ... Args >
	struct decay< T(Args...)&& >
	{
		using type = T;
	};

	template< typename T, typename ... Args >
	struct decay< const T(Args...)&& >
	{
		using type = T;
	};

	template < typename T, std::size_t N >
	struct decay < T[N] >
	{
		using type = T;
	};

	template < typename T >
	struct decay < T[] >
	{
		using type = T;
	};


	template<typename T1, typename T2>
	void print_is_same() {
		std::cout << std::is_same<T1, T2>() << '\n';
	}
	template <class _Ty>
	using decay_t = typename decay<_Ty>::type;
}

int main()
{
	int const* const A = new int[10];
	std::cout << std::boolalpha;
	My::print_is_same<int, My::decay_t<int>>();
	My::print_is_same<int, My::decay_t<int const>>();
	My::print_is_same<int*, My::decay_t<int* const>>();
	My::print_is_same<int**, My::decay_t<int** const>>();
	My::print_is_same<int, My::decay_t<int &>>();
	My::print_is_same<int, My::decay_t<int&&>>();
	My::print_is_same<int, My::decay_t<int const &>>();
	My::print_is_same<int, My::decay_t<int const &&>>();
	My::print_is_same<int*, My::decay_t<int* const &&>>();
	My::print_is_same<int, My::decay_t<int (int a, int b) >>();
	My::print_is_same<int, My::decay_t<const int[] >>();

}


