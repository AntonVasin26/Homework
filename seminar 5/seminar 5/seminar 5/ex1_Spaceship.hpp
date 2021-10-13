#include "list_function.hpp"

class Spaceship
{
public:   
	explicit Spaceship(const std::string& name, const double ship_mass, double fuel_tank_limit,
		double energy_bar_limit, unsigned int crew_capacity, double storage_capacity) :
		name(name), sm(ship_mass), flim(fuel_tank_limit), elim(energy_bar_limit), crlim(crew_capacity), stlim(storage_capacity)
	{
		std::cout << "\ncreate " << name;
	}

	void add_passenger(const std::string& name_p, double mass_p);
	void get_passenger(const std::string& name_p);
	
	void add_luggage(const std::string& name_l, double mass_l);
	void get_luggage(const std::string& name_l);

	void fill_up_fuel(int m);
	void fill_up_energy(int m);

	void move(double learn);
	void condition();

	~Spaceship()
	{
		std::cout << "\ndelete " << name;
	}

private:
	std::string name;
	const double sm;

	const double flim;
	double ft = 0;

	const double elim;
	double eb = 0;

	const unsigned int crlim;
	double cm = 0;

	const double stlim;
	double stm = 0.0;

	double full_mass = 0;
	std::map <std::string, double> crew;
	std::map <std::string, double> storage;
};