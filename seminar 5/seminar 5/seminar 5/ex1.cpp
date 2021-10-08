#include "list_function.hpp"
#include "ex1_Spaceship.hpp"

void ex1()
{
	std::cout << "\nex1 start\n";

	Spaceship borey("Borey", 100, 1000, 2000, 6, 400);
	borey.condition();
	borey.add_passenger("Anton", 90);
	borey.add_luggage("laptop", 2);
	borey.fill_up_energy(2300);
	borey.fill_up_fuel(200);
	borey.condition();
	borey.move(100);
	borey.fill_up_fuel(900);
	borey.move(100);
	borey.get_luggage("laptop");
	borey.get_luggage("mouse");
	std::cout << "\n\nex1 end\n";
}