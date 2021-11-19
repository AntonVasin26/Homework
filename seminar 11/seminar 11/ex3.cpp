#include <iostream>
#include <type_traits>

namespace My
{
	template < typename T >
	struct remove_const
	{
		using type = T;
	};

	template < typename T >
	struct remove_const < T const >
	{
		using type = T;
	};

	template <class _Ty>
	using remove_const_t = typename remove_const<_Ty>::type;

	template < typename T >
	struct remove_reference
	{
		using type = T;
	};

	template < typename T >
	struct remove_reference < T& >
	{
		using type = T;
	};

	template < typename T >
	struct remove_reference < T&& >
	{
		using type = T;
	};

	template <class _Ty>
	using remove_reference_t = typename remove_reference<_Ty>::type;

	template < typename T >
	struct decay
	{
		using type1 = remove_reference_t<T>;
		using type = remove_const_t<type1>;
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
	std::cout << std::boolalpha;
	My::print_is_same<int, My::decay_t<int>>();
	My::print_is_same<int, My::decay_t<int const>>();
	My::print_is_same<int*, My::decay_t<int* const>>();
	My::print_is_same<int**, My::decay_t<int** const>>();
	My::print_is_same<int, My::decay_t<int &>>();
	My::print_is_same<int, My::decay_t<int&&>>();
	My::print_is_same<int, My::decay_t<int const &>>();
	My::print_is_same<int, My::decay_t<int const &&>>();
	My::print_is_same<int*, std::decay_t<int* const &&>>();
}


