#include <iostream>
#include <valarray> 

using namespace std;

// copied from https://stackoverflow.com/questions/26643695/converting-a-floating-point-decimal-value-to-a-fraction , second answer
void as_fraction(double number, int& num, unsigned& denum, int cycles = 10, double precision = 5e-4) {
    int sign = number > 0 ? 1 : -1;
    number = number * sign; //abs(number);
    double new_number, whole_part;
    double decimal_part = number - (int)number;
    int counter = 0;

    valarray<double> vec_1{ double((int)number), 1 }, vec_2{ 1,0 }, temporary;

    while ((decimal_part > precision) && (counter < cycles)) {
        new_number = 1 / decimal_part;
        whole_part = (int)new_number;

        temporary = vec_1;
        vec_1 = whole_part * vec_1 + vec_2;
        vec_2 = temporary;

        decimal_part = new_number - whole_part;
        counter += 1;
    }
    num = sign * vec_1[0];
    denum = vec_1[1];
}