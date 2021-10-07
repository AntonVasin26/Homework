#include "list_function.hpp"
#include "ex1_Spaceship.hpp"

void ex1()
{
	std::cout << "\nex1 start\n";

	Spaceship Borey("Borey", 100, 1000, 2000, 6, 400);
	Borey.condition();
	Borey.add_passenger("Anton", 90);
	Borey.add_luggage("laptop", 2);
	Borey.fill_up_energy(2300);
	Borey.fill_up_fuel(200);
	Borey.condition();
	Borey.move(100);
	Borey.fill_up_fuel(900);
	Borey.move(100);
	Borey.get_luggage("laptop");
	Borey.get_luggage("mouse");
	std::cout << "\n\nex1 end\n";
}