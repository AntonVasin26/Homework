#include "Header.hpp"

template< typename Derived>
class Car
{
public:
	Car(std::string num): number(num) {}
	Derived * self()
	{
		return static_cast <Derived*> (this);
	}

	void print()
	{
		self()->print_V();
		std::cout << "number: " << number << '\n';
	}
private:
	std::string number;

};

class KIA : public Car <KIA>
{
public:
	KIA(std::string num): Car(num) {}
	void print_V()
	{
		std::cout << "KIA;";
	}
};

class VAZ : public Car <VAZ>
{
public:
	VAZ(std::string num) : Car(num) {}
	void print_V()
	{
		std::cout << "VAZ;";
	}
};

void ex4()
{
	std::string num = "2sff45";
	KIA C1(num);
	VAZ C2(num);
	C1.print();
	C2.print();
}