#include "function_set.hpp"


void f2()
{
    std::vector <double > ans;
    auto n = 30U;
    for (double i = 0.0; i < n; i++)
    {
        ans.push_back(i);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(ans.begin(), ans.end(), g);;


    std::cout << "Input list:\t";
    for (auto i : ans)
    {
        std::cout << i << " ";
    }
    merge_sort(ans, 0, std::size(ans) - 1);

    std::cout << "\nOutput list:\t";

    for (auto i : ans)
    {
        std::cout << i << " ";
    }
    std::cout << '\n' << std::endl;
}


void merge(std::vector<double> &main_list, int l, int r)
{
    auto mid = (l + r) / 2;
    auto i = l;
    auto j = mid + 1;
    std::vector <double> dop_list;
    for (auto step = 0; step < r - l + 1; step++)
    {
        if ((j > r) || ((i <= mid) && (main_list[i] < main_list[j])))
        {
            dop_list.push_back(main_list[i]);
            i++;
        }
        else
        {
            dop_list.push_back(main_list[j]);
            j++;
        }
    }
    for (auto step = 0; step < r - l + 1; step++)
    {
        main_list[l + step] = dop_list[step];
    }
}

void merge_sort(std::vector <double> &list, int l, int r)
{
	if (l == r) return;
	auto mid = (l + r) / 2;
	merge_sort(list, l, mid);
	merge_sort(list, mid + 1, r);
    merge(list, l, r);
}