#include "Header.hpp"

using namespace std;

void as_fraction(const double& number, int& num, unsigned& denom, const int pVal)
{
    int intVal = floor(number);
    double fVal = number - intVal + 0.1/pVal;

    int gcdVal = std::gcd(static_cast<int>(fVal * pVal), pVal);
    int num0 = static_cast<int>(fVal * pVal) / gcdVal;

    denom = pVal / gcdVal;
    num = (static_cast<int>(intVal) * denom) + num0;
}