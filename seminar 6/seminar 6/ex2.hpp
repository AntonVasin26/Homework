#pragma once
#include "Header.hpp"

namespace My_space
{
	class Fraction
	{
	private:
		int numerator;
		unsigned int denominator;
	public:
		Fraction() : numerator(0), denominator(1) {}

		Fraction(int n) : numerator(n), denominator(1U) {}

		Fraction(double x) { as_fraction(x, numerator, denominator, std::pow(10, 6)); simplify(); }

		Fraction(int n, unsigned int m = 1) : numerator(n), denominator(m) { simplify(); }

		Fraction(const Fraction& f) = default;

		Fraction(Fraction&& f) = default;

		~Fraction() = default;

		Fraction& operator= (const Fraction& other) = default;
		Fraction& operator= (Fraction&& other) = default;

		explicit operator double()const { return static_cast<double>(numerator) / static_cast<double>(denominator); }
		explicit operator int()const { return get_whole_part(); }

		void simplify();
		int get_whole_part() const { return  numerator / denominator; }
		Fraction const get_fractional_part();
		int get_numerator() const { return numerator; }
		int get_denominator() const { return denominator; }

		Fraction& operator += (const Fraction& other);
		Fraction& operator -= (const Fraction& other);
		Fraction& operator *= (const Fraction& other);
		Fraction& operator /= (const Fraction& other);
		friend Fraction pow(const Fraction &f, int n);
		friend Fraction pow(const Fraction& f, double n);

		friend Fraction operator+ (const Fraction& a, const Fraction& b);
		friend Fraction operator- (const Fraction& a, const Fraction& b);
		friend Fraction operator* (const Fraction& a, const Fraction& b);
		friend Fraction operator/ (const Fraction& a, const Fraction& b);

		Fraction& operator++() {numerator += denominator; simplify(); return *this;}
		Fraction& operator--() {numerator -= denominator; simplify(); return *this;}
		Fraction& num_plus(int n) {numerator += n; simplify(); return *this; };
		Fraction& num_minus(int n) { numerator -= n; simplify(); return *this; };
		Fraction& denom_plus(int n);
		Fraction& denom_minus(int n);



		friend std::ostream& operator << (std::ostream& os, const Fraction& q);
		friend std::istream& operator>>(std::istream& in, Fraction& f1);

		friend const bool operator== (const Fraction& f1, const Fraction& f2) 
		{return (f1.numerator == f2.numerator && f1.denominator == f2.denominator);}

		friend const bool operator!= (const Fraction& f1, const Fraction& f2)
		{return !(f1 == f2);}

		friend const bool operator> (const Fraction& f1, const Fraction& f2)
		{return f1.numerator * f2.denominator > f2.numerator * f1.denominator;}

		friend const bool operator>= (const Fraction& f1, const Fraction& f2)
		{return (f1 > f2 || f1 == f2);}

		friend const bool operator< (const Fraction& f1, const Fraction& f2)
		{return !(f1 >= f2);}

		friend const bool operator<= (const Fraction& f1, const Fraction& f2)
		{return (f1 < f2 || f1 == f2);}
	};
}