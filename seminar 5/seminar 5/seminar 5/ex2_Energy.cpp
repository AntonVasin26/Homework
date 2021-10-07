#include "list_function.hpp"
#include "ex2_Energy.hpp"

void Energy::change_unit_to(const Energy::E_units unit)
{
	//Из единицы в джоули
	switch (e_unit)
	{
	case Energy::E_units::Joule:
		break;
	case Energy::E_units::erg:
		if (e_value > epsilon * pow(10, 7))
		{
			e_value *= pow(10, -7);
		}
		else {std::cout << "the number is too small";}
		break;
	case Energy::E_units::cal:
		e_value *= 9.80665;
		break;
	case Energy::E_units::eV:
		if (e_value > epsilon * pow(10, 19))
		{
			e_value *= (1.60219 * pow(10, -19));
		}
		else { std::cout << "the number is too small"; }
		break;
	case Energy::E_units::kgs:
		e_value *= 9.80665;
		break;
	case Energy::E_units::kWt_h:
		e_value *= 3.6 * pow(10, 6);
		break;
	case Energy::E_units::l_atm:
		e_value *= 101.3278;
		break;
	default:
		break;
	}
	if (e_value > epsilon * pow(10, 7))
	{
		switch (unit)
		{
		case Energy::E_units::Joule:
			break;
		case Energy::E_units::erg:
			e_value /= pow(10, -7);
			break;
		case Energy::E_units::cal:
			e_value /= 9.80665;
			break;
		case Energy::E_units::eV:
			e_value /= (1.60219 * pow(10, -19));
			break;
		case Energy::E_units::kgs:
			e_value /= 9.80665;
			break;
		case Energy::E_units::kWt_h:
			e_value /= 3.6 * pow(10, 6);
			break;
		case Energy::E_units::l_atm:
			e_value /= 101.3278;
			break;
		default:
			break;
		}
		e_unit = unit;
	}
	else
	{
		std::cout << "\nthe number is too small";
		std::cout << "\n Save value in Joule";
		e_unit = Energy::E_units::Joule;
	}
	
}

