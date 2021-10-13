#include "list_function.hpp"
#include "ex2_Energy.hpp"

void Energy::change_unit_to(const Energy::E_units& unit)
{
	//Из единицы в джоули
	switch (e_unit)
	{
	case Energy::E_units::Joule:
		break;
	case Energy::E_units::erg:
		if (e_value > epsilon / m_erg)
		{
			e_value *= m_erg;
		}
		else {std::cout << "the number is too small";}
		break;
	case Energy::E_units::cal:
		e_value *= m_cal;
		break;
	case Energy::E_units::eV:
		if (e_value > epsilon / m_eV)
		{
			e_value *= m_eV;
		}
		else { std::cout << "the number is too small"; }
		break;
	case Energy::E_units::kgs:
		e_value *= m_kgs;
		break;
	case Energy::E_units::kWt_h:
		e_value *= m_kWt_h;
		break;
	case Energy::E_units::l_atm:
		e_value *= m_l_atm;
		break;
	default:
		break;
	}
	if (e_value > epsilon * m_kWt_h)
	{
		switch (unit)
		{
		case Energy::E_units::Joule:
			break;
		case Energy::E_units::erg:
			e_value /= m_erg;
			break;
		case Energy::E_units::cal:
			e_value /= m_cal;
			break;
		case Energy::E_units::eV:
			e_value /= m_eV;
			break;
		case Energy::E_units::kgs:
			e_value /= m_kgs;
			break;
		case Energy::E_units::kWt_h:
			e_value /= m_kWt_h;
			break;
		case Energy::E_units::l_atm:
			e_value /= m_l_atm;
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

