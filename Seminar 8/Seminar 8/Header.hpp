#pragma once
#include <iostream>
#include <random>
#include <variant>
#include <cassert>
#include <stdexcept>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
#include <source_location>
#include <exception>

void ex1();
void ex2();
enum class MyError;
class Division_by_zero;
int f3(int a, int b, int c);
void f4(int a[], std::size_t l, int b);
int f5(int x, int y);
int f6(double x);
double f7(double x, double y);
void ex3();
void as_fraction(const double& number, int& num, unsigned& denom, const int pVal);