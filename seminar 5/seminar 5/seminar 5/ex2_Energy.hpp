#include "list_function.hpp"

class Energy
{
public:
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
	Energy(long double value) :
		e_value(value), e_unit(Energy::E_units::Joule)
	{}
	Energy(long double value, const Energy::E_units& unit) :
		e_value(value), e_unit(unit)
	{}
	void change_unit_to(const Energy::E_units& unit);

	const auto const get_value()
	{
		return e_value;
	}

	const auto const get_unit()
	{
		return e_unit;
	}

	void print()
	{
		std::cout << '\n' << std::scientific << e_value;
	}

private:
	long double e_value;
	E_units e_unit;
	static inline const double epsilon = std::numeric_limits<long double>::epsilon();
	static inline const double m_erg = pow(10, -7);
	static inline const double m_cal = 4.1868;
	static inline const double m_eV = 1.60219 * pow(10, -19);
	static inline const double m_kgs = 9.80665;
	static inline const double m_kWt_h = 3.6 * pow(10, 6);
	static inline const double m_l_atm = 101.3278;
};