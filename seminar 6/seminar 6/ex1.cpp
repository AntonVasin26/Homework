#include "Header.hpp"

class Arr_Var_Vec
{
private:
	std::vector<int> vec;
	int arr_length;
	int* arr_data;

public:
	Arr_Var_Vec() : arr_data(nullptr), arr_length(0), vec() {}
	Arr_Var_Vec(int length, const std::vector<int>& arr, const std::vector<int>& v);
	Arr_Var_Vec(const Arr_Var_Vec& other);
	Arr_Var_Vec(Arr_Var_Vec&& other);
	Arr_Var_Vec& operator= (const Arr_Var_Vec& other);
	Arr_Var_Vec& operator= (Arr_Var_Vec&& other);
	~Arr_Var_Vec()
	{
		if (arr_data)
		{
			delete[] arr_data;
			vec.clear();
		}
	}
	void print();

};
Arr_Var_Vec::Arr_Var_Vec(int length, const std::vector<int>& arr, const std::vector<int>& v) : arr_length(length), vec(v)
{
	arr_data = new int[length];
	if (length > std::size(arr))
	{
		for (auto i = 0; i < std::size(arr); ++i)
			arr_data[i] = arr[i];
		for (auto i = std::size(arr); i < length; ++i)
			arr_data[i] = 0;
	}
	else
	{
		std::cout << "\narray index out of range\n";
	}
}

Arr_Var_Vec::Arr_Var_Vec(const Arr_Var_Vec& other) : arr_length(other.arr_length), vec(other.vec)
{
	arr_data = new int[arr_length];
	for (auto i = 0; i < arr_length; ++i)
		arr_data[i] = other.arr_data[i];
}

Arr_Var_Vec::Arr_Var_Vec(Arr_Var_Vec&& other) : arr_length(other.arr_length), arr_data(other.arr_data), vec(std::move(other.vec))
{
	other.arr_length = 0;
	other.arr_data = nullptr;
	std::vector<int>().swap(other.vec);
}

Arr_Var_Vec & Arr_Var_Vec::operator= (const Arr_Var_Vec& other)
{
	if (this == &other) return *this;
	if (arr_data)
	{
		delete[] arr_data;
	}
	arr_length = other.arr_length;
	arr_data = new int[arr_length];
	for (auto i = 0; i < arr_length; ++i)
		arr_data[i] = other.arr_data[i];
	vec = other.vec;
	return *this;
}

Arr_Var_Vec & Arr_Var_Vec::operator= (Arr_Var_Vec&& other)
{
	if (this == &other) return *this;
	if (arr_data)
	{
		delete[] arr_data;
	}
	arr_length = other.arr_length;
	arr_data = other.arr_data;
	other.arr_length = 0;
	other.arr_data = nullptr;
	vec = std::move(other.vec);
	return *this;
};

void Arr_Var_Vec::print()
{
	std::cout << '\n' << arr_length << '\n';
	for (auto i = 0; i < arr_length; ++i)
	{
		std::cout << arr_data[i] << '\t';
	}
	std::cout << '\n';
	for (auto i : vec)
	{
		std::cout << i << '\t';
	}
}

int main()
{
	std::vector<int> v1 = { 1,2,3 };
	std::vector<int> v2 = { 1,2,3 };
	Arr_Var_Vec a1(5, v1, v2);
	a1.print();
	Arr_Var_Vec a2(a1);
	a2.print();
	Arr_Var_Vec a3(std::move(a1));
	a3.print();
	a1.print();
	std::cout << "\n--------------------------------------------\n";
	Arr_Var_Vec a4(10, {1,1,1 }, { 9,8,7,6 });
	Arr_Var_Vec a5;
	a5.print();
	a5 = a4;
	a4.print();
	a5.print();
	a5 = std::move(a4);
	a4.print();
	a5.print();

}