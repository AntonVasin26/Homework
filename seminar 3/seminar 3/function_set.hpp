#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <cmath>


void f1();
void f2();
void f3();
void f4();

void merge_sort(std::vector <double> &list, int l, int r);
int fibonachi(int n);
double calculate(double x, double y, std::function <double(double, double)> f);
