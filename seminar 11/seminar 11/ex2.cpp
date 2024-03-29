#include <iostream>
#include <type_traits>



template < typename T >
struct remove_const
{
	using type = T;
};

template < typename T >
struct remove_const < const T >
{
	using type = T;
};

//You musn't to do that
//template < typename T >
//struct remove_const < const T& >
//{
//	using type = T&;
//};
//
//template < typename T >
//struct remove_const < const T&& >
//{
//	using type = T&&;
//};

template < typename T >
struct add_const
{
	using type = const T;
};

//You musn't to do that
//template < typename T >
//struct add_const < T& >
//{
//	using type = const T&;
//};
//
//template < typename T >
//struct add_const < T&& >
//{
//	using type = const T&&;
//};

template <class _Ty>
using remove_const_t = typename remove_const<_Ty>::type;

template<typename T1, typename T2>
void print_is_same() {
	std::cout << std::is_same<T1, T2>() << '\n';
}

int main() 
{
	std::cout << std::boolalpha;
	print_is_same<int, int>();
	print_is_same<int, const int>();
	print_is_same<int&, const int&>();
	print_is_same<int&&, const int&&>();
	std::cout << "----------------------------------------\n";
	print_is_same<int, const int>();
	print_is_same<int, remove_const<const int>::type>();
	print_is_same<int, remove_const_t<const int>>();
	print_is_same<int&, remove_const<const int&>::type>();
	print_is_same<int&&, remove_const<const int&&>::type>();
	print_is_same<int* , std::remove_const<int*const>::type>();
	std::cout << "----------------------------------------\n";
	print_is_same<const int, int>();
	print_is_same<const int, add_const<int>::type>();
	print_is_same<const int&, add_const<int&>::type>();
	print_is_same<const int&&, add_const<int&&>::type>();
}

