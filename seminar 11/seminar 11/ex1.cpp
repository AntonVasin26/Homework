#include <iostream>
#include <type_traits>

template< typename T>
struct is_function : std::false_type { using type = T; };

template< typename T, typename ... Args >
struct is_function< T(Args...) > : std::true_type { using type = T; };

template< typename T, typename ... Args >
struct is_function< T(Args...)&> : std::true_type { using type = T&; };

template< typename T, typename ... Args >
struct is_function< T(Args...)&& > : std::true_type { using type = T&&; };

template< typename T, typename ... Args >
struct is_function< const T(Args...) > : std::true_type { using type = const T; };

template< typename T, typename ... Args >
struct is_function< const T(Args...)& > : std::true_type { using type = const T&; };

template< typename T, typename ... Args >
struct is_function< const T(Args...)&& > : std::true_type {using type = const T&&;};

template <typename T>
inline constexpr bool is_function_v = is_function< T >::value;


template<typename T1, typename T2>
void print_is_same() 
{
	std::cout << std::is_same<T1, T2>() << '\n';
}

int f(int a)
{
	return a;
}

int main()
{
	std::cout << std::boolalpha;
	std::cout << is_function_v< int > << '\n';
	std::cout << is_function_v< int(int a, int b) > << '\n';
	std::cout << is_function_v< const double() > << '\n';
	std::cout << is_function_v< double*() > << '\n';
	std::cout << is_function_v< decltype(f) > << '\n';
	std::cout << "-------------------------------------------\n";
	print_is_same<is_function< decltype(f) > ::type, int>() ;
	print_is_same<is_function< double& > ::type, double&>();
	print_is_same<is_function< double > ::type, int>();
	print_is_same<is_function< double* > ::type, int>();
	//print_is_function_v < [](int i){return ((i % 2) == 0);}> ();
}


