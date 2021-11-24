#include <iostream>
#include <type_traits>

namespace My
{
	template< typename T>
	struct is_function : std::false_type { using type = T; };

	template< typename T, typename ... Args >
	struct is_function< T(Args...) > : std::true_type { using type = T; };

	template< typename T, typename ... Args >
	struct is_function< T(Args...)&> : std::true_type { using type = T; };

	template< typename T, typename ... Args >
	struct is_function< T(Args...)&& > : std::true_type { using type = T; };

	template< typename T, typename ... Args >
	struct is_function< const T(Args...) > : std::true_type { using type = T; };

	template< typename T, typename ... Args >
	struct is_function< const T(Args...)& > : std::true_type { using type = const T; };

	template< typename T, typename ... Args >
	struct is_function< const T(Args...)&& > : std::true_type { using type = const T; };

	template <typename T>
	inline constexpr bool is_function_v = is_function< T >::value;

	template < typename T >
	using is_function_t = typename is_function < T >::type;

//------------------------------------------------------------------

	template < bool C, typename True_Type, typename False_Type >
	struct if_then_else
	{
		using type = True_Type;
	};

	template < typename True_Type, typename False_Type >
	struct if_then_else < false, True_Type, False_Type >
	{
		using type = False_Type;
	};

	template < bool C, typename TT, typename FT >
	using if_then_else_t = typename if_then_else < C, TT, FT >::type;
	
	template <typename T>
	struct decay
	{
		using T1 = std::remove_reference_t <T>;
		using type = if_then_else_t < std::is_array_v <T1>, std::remove_extent_t <T>,
			if_then_else_t <is_function_v<T1>, is_function_t<T1>, std::decay_t<T1> > >;
	};

	template <typename T>
	using decay_t = typename decay<T>::type;

	template<typename T1, typename T2>
	void print_is_same()
	{
		std::cout << std::is_same<T1, T2>() << '\n';
	}

}

int main()
{
	int A[10];
	const int* B = new int[5];
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

	My::print_is_same<std::decay_t<decltype(A)>, decltype(A)>();
	My::print_is_same<std::decay_t<decltype(B)>, decltype(B)>();


}


