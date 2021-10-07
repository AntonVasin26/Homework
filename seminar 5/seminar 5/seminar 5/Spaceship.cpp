#include "list_function.hpp"
#include "ex1.hpp"
void Spaceship::add_passenger(const std::string& name_p, double mass_p)
{
	if (crew.size() <= crlim && storage.find(name_p) == storage.end())
	{
		std::cout << "\nadd_passenger: " << name_p;
		crew.insert(make_pair(name_p, mass_p));
		cm += mass_p;
	}
	else if (crew.size() <= crlim)
	{
		std::cout << "\nno available seats";
	}
	else
	{
		std::cout << "\npassenger with that name already exists";
	}
}

void Spaceship::get_passenger(const std::string& name_p)
{
	auto f = crew.find(name_p);
	if (f != crew.end())
	{
		std::cout << "\nget_passenger: " << name_p;
		cm -= crew[name_p];
		crew.erase(f);
	}
	else
	{
		std::cout << "\npassenger <<" << name_p << ">> not found";
	}
}

void Spaceship::add_luggage(const std::string& name_l, double mass_l)
{
	if (stm + mass_l <= stlim && storage.find(name_l) == storage.end())
	{
		std::cout << "\nadd_luggage: " << name_l;
		storage.insert(make_pair(name_l, mass_l));
		stm += mass_l;
	}
	else if (stm + mass_l <= stlim)
	{
		std::cout << "\nnot enough space";
	}
	else
	{
		std::cout << "\nluggage with that name already exists";
	}
}

void Spaceship::get_luggage(const std::string& name_l)
{
	auto f = storage.find(name_l);
	if (f != storage.end())
	{
		std::cout << "\nget_luggage: " << name_l;
		stm -= storage[name_l];
		storage.erase(f);
	}
	else
	{
		std::cout << "\nluggage <<" << name_l << ">> not found";
	}
}

void Spaceship::fill_up_fuel(int m)
{
	if (ft + m <= flim)
	{
		ft += m;
		std::cout << '\n' << name << "\tfuel_tank: " << ft << "/" << flim;
	}
	else
	{
		std::cout << '\n' << name << "\tfuel_tank Full; adeed: " << flim - ft;
		ft = flim;
	}
}

void Spaceship::fill_up_energy(int m)
{
	if (eb + m <= elim)
	{
		eb += m;
		std::cout << '\n' << name << "\tenergy_bar: " << eb << "/" << elim;
	}
	else
	{
		std::cout << '\n' << name << "\tenergy_bar Full; adeed: " << elim - eb;
		eb = elim;
	}
}

void Spaceship::move(float learn)
{
	full_mass = sm + cm + stm;
	if (eb <= learn)
	{
		std::cout << "\nfail -- few energy";
	}
	if (ft < (2 * full_mass + learn))
	{
		std::cout << "\nfail -- few fuel";
	}
	if (eb > learn && ft > (2 * full_mass + learn))
	{
		eb -= learn;
		ft -= (2 * full_mass + learn);
		std::cout << "\nmoving successfully";
	}
	std::cout << '\n' << name << "\tfuel_tank: " << ft << "/" << flim << "\tenergy_bar: " << eb << "/" << elim;
}

void Spaceship::condition()
{
	full_mass = sm + cm + stm;
	std::cout << '\n' << name << "\ntotal mass: " << full_mass << "\tfuel_tank: " << ft << "/" << flim << "\tenergy_bar: " << eb << "/" << elim;
	std::cout << "\nmass crew:" << cm;
	for (auto i : crew)
	{
		std::cout << '\n' << i.first << ": " << i.second;
	}
	std::cout << "\nmass storage:" << stm;
	for (auto i : storage)
	{
		std::cout << '\n' << i.first << ": " << i.second;
	}
}


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