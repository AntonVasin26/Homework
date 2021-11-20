#include <iostream>
#include <type_traits>


template<bool B, typename T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { using type = T; };

template< bool B, typename T = void >
using enable_if_t = typename enable_if<B, T>::type;

class Person
{
public:
	template < typename S, typename Enable =
		enable_if_t < std::is_convertible_v < S, std::string > > >
		explicit Person(S&& name) :
		m_name(std::forward < S >(name))
	{
		std::cout << "CTOR\n";
	}

	Person(const Person& person) :
		m_name(person.m_name)
	{
		std::cout << "COPY-CTOR Person '" << m_name << "'\n";
	}

	Person(Person&& p) noexcept :
		m_name(std::move(p.m_name))
	{
		std::cout << "MOVE-CTOR Person '" << m_name << "'\n";
	}

	~Person() noexcept = default;

private:

	std::string m_name;
};

int main(int argc, char** argv)
{
	std::string s = "Ivan";

	Person p1(s);
	Person p2("tmp");
	Person p3(p1);
	Person p4(std::move(p1));

	system("pause");

	return EXIT_SUCCESS;
}