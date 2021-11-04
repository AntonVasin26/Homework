#pragma once
#include "Header.hpp"

namespace My_space
{
	class Division_by_zero : public std::logic_error
	{
	public:
		explicit Division_by_zero() : logic_error("Division_by_zero: " + '\n') {}
		explicit Division_by_zero(const std::string& _Message) : logic_error( ("Division_by_zero: " + _Message + '\n').c_str()) {}
		~Division_by_zero() noexcept = default;

	};

	class Fractional_power_of_a_negative_number : public std::logic_error 
	{
	public:
		explicit Fractional_power_of_a_negative_number() :
			logic_error("Fractional_power_of_a_negative_number: " + '\n') {}
		explicit Fractional_power_of_a_negative_number(const std::string& _Message) :
			logic_error(("Fractional_power_of_a_negative_number: " + _Message + '\n').c_str()) {}
		~Fractional_power_of_a_negative_number() noexcept = default;
	};

	class Fraction
	{
	private:
		int numerator;
		unsigned int denominator;
	public:
		Fraction() noexcept: numerator(0), denominator(1) {}

		Fraction(int n) noexcept: numerator(n), denominator(1U) { simplify(); }

		Fraction(double x) { as_fraction(x, numerator, denominator, std::pow(10, 6)); simplify(); }

		Fraction(int n, int m) : numerator(n)
		{ 
			if (m <= 0)
			{
				throw std::invalid_argument("denominator = m <= 0");
			}
			else
			{
				denominator = m;
				simplify();
			}
		}

		Fraction(const Fraction& f) noexcept = default;

		Fraction(Fraction&& f) noexcept = default;

		~Fraction() noexcept = default;

		Fraction& operator= (const Fraction& other)noexcept = default;
		Fraction& operator= (Fraction&& other)noexcept = default;

		explicit operator double()const noexcept { return static_cast<double>(numerator) / static_cast<double>(denominator); }
		explicit operator int() const noexcept { return get_whole_part(); }

		void simplify()noexcept;
		int get_whole_part() const noexcept { return  numerator / denominator; }
		Fraction const get_fractional_part() noexcept;
		int get_numerator() const noexcept { return numerator; }
		int get_denominator() const noexcept { return denominator; }

		Fraction& operator += (const Fraction& other) noexcept ;
		Fraction& operator -= (const Fraction& other) noexcept;
		Fraction& operator *= (const Fraction& other) noexcept;
		Fraction& operator /= (const Fraction& other);
		friend Fraction pow(const Fraction& f, int n) noexcept;
		friend Fraction pow(const Fraction& f, double n); 

		friend Fraction operator+ (const Fraction& a, const Fraction& b) noexcept;
		friend Fraction operator- (const Fraction& a, const Fraction& b) noexcept;
		friend Fraction operator* (const Fraction& a, const Fraction& b) noexcept;
		friend Fraction operator/ (const Fraction& a, const Fraction& b) ;

		Fraction& operator++() noexcept {numerator += denominator; simplify(); return *this;}
		Fraction& operator--() noexcept {numerator -= denominator; simplify(); return *this;}
		Fraction& operator++(int) noexcept { numerator += denominator; simplify(); return *this; }
		Fraction& operator--(int) noexcept { numerator -= denominator; simplify(); return *this; }

		friend std::ostream& operator << (std::ostream& os, const Fraction& q) noexcept;
		friend std::istream& operator>>(std::istream& in, Fraction& f1);

		friend const bool operator== (const Fraction& f1, const Fraction& f2) noexcept
		{return (f1.numerator == f2.numerator && f1.denominator == f2.denominator);}

		friend const bool operator!= (const Fraction& f1, const Fraction& f2) noexcept
		{return !(f1 == f2);}

		friend const bool operator> (const Fraction& f1, const Fraction& f2) noexcept
		{return f1.numerator * f2.denominator > f2.numerator * f1.denominator;}

		friend const bool operator>= (const Fraction& f1, const Fraction& f2) noexcept
		{return (f1 > f2 || f1 == f2);}

		friend const bool operator< (const Fraction& f1, const Fraction& f2) noexcept
		{return !(f1 >= f2);}

		friend const bool operator<= (const Fraction& f1, const Fraction& f2) noexcept
		{return (f1 < f2 || f1 == f2);}
	};
}