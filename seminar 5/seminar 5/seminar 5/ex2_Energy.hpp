#include "list_function.hpp"

class Energy
{
public:
	enum class E_units;
	Energy(long double value) :
		e_value(value), e_unit(Energy::E_units::Joule)
	{}
	Energy(long double value, const Energy::E_units& unit) :
		e_value(value), e_unit(unit)
	{}
	void change_unit_to(const Energy::E_units unit);

	long double const get_value()
	{
		return e_value;
	}

	const E_units& get_unit()
	{
		return e_unit;
	}

	void print()
	{
		std::cout << '\n' << std::scientific << e_value;
	}
	enum class E_units
	{
		Joule,
		erg,
		kgs,
		kWt_h,
		l_atm,
		cal,
		eV
	};

private:
	long double e_value;
	E_units e_unit;
	static inline const double epsilon = std::numeric_limits<long double>::epsilon();

};