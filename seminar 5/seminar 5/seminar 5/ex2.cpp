#include "list_function.hpp"
#include "ex2_Energy.hpp"

void ex2()
{
	std::cout << "\n\n ex2 start \n\n";
	Energy a(14000.06674);
	Energy::E_units val = a.get_unit();
	Energy b(534 * pow(10, 23), Energy::E_units::eV);
	a.print();
	a.change_unit_to(Energy::E_units::erg);
	a.print();
	std::cout << '\n' << a.get_value();
	b.print();
	b.change_unit_to(Energy::E_units::Joule);
	b.print();
	std::cout << "\n\n ex2 end \n\n";
}