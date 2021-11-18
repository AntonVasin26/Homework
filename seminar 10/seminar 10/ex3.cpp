#include "Header.hpp"

template <typename Func, typename ... Args>
void call(Func&& f, Args && ... args)
{
	f(std::forward<Args>(args)...);
}

void ex3()
{
	call([](auto x, auto y) { std::cout << x + y << '\n'; }, 10, 15);
	call([](auto x, auto y) { std::cout << x + y << '\n'; }, 10.34, 15.547);
	call([](std::string x, std::string y) { std::cout << x + y << '\n'; }, "aaaa", "bbbb");
}
