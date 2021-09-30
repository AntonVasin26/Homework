#include "list_function.hpp"

struct Spaceship
{
	const std::string name;
	float fuel_tank;
	float energy_bar;
	std::vector <std::string> crew = { "auto" };
	std::vector <std::string> storage;
	int mass = 5;
	Spaceship(const std::string name, float fuel_tank = 0, float energy_bar = 0) :
		name(name), fuel_tank(fuel_tank), energy_bar(energy_bar)
	{
		std::cout << "\ncreate " << name;
	}

	void add_passenger(std::string name_p)
	{
		std::cout << "\nadd_passenger: " << name_p;
		crew.push_back(name_p);
		mass = 5 + size(crew) + size(storage);
	}

	void add_luggage(std::string name_l)
	{
		std::cout << "\nadd_luggage: " << name_l;
		crew.push_back(name_l);
		mass = 5 + size(crew) + size(storage);
	}

	void fill_up_fuel(int m)
	{
		fuel_tank += m;
		std::cout << '\n' << name << "\tfuel_tank: " << fuel_tank << "\tenergy_bar: " << energy_bar;
	}

	void fill_up_energy(int m)
	{
		energy_bar += m;
		std::cout << '\n' << name << "\tfuel_tank: " << fuel_tank << "\tenergy_bar: " << energy_bar;
	}

	void move(float learn)
	{
		if (energy_bar < learn)
		{
			std::cout << "\nfail -- few energy";
		}
		if (fuel_tank < (2 * mass + learn))
		{
			std::cout << "\nfail -- few fuel";
		}
		if (energy_bar > learn && fuel_tank > (2 * mass + learn))
		{
			energy_bar -= learn;
			fuel_tank -= (2 * mass + learn);
			std::cout << "\nmoving successfully";
		}
		std::cout << '\n' << name << "\tfuel_tank: " << fuel_tank << "\tenergy_bar: " << energy_bar;
	}
	void condition()
	{
		std::cout << '\n' << name << "\tfuel_tank: " << fuel_tank << "\tenergy_bar: " << energy_bar;
		std::cout << "\ncrew:";
		for (auto i : crew)
		{
			std::cout << '\n' << i;
		}
		std::cout << "\nstorage:";
		for (auto i : storage)
		{
			std::cout << '\n' << i;
		}
	}

	~Spaceship()
	{
		std::cout << name << " was destroed";
	}
};

void ex1()
{
	std::cout << "\nex1 start\n";
	Spaceship Borey("Borey", 200, 100);
	Borey.condition();
	Borey.move(10);
	Borey.add_passenger("Anton");
	Borey.add_luggage("laptop");
	Borey.fill_up_energy(50);
	Borey.fill_up_fuel(100);
	Borey.move(50);
	Borey.move(200);
	std::cout << "\n\nex1 end\n";
}