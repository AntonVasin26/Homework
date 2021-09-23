#include "function_set.hpp"

void f2()
{
	std::vector <double> ans = { 5,12,34,55,11,32,42,1,2,43,6,7,5,23,45,65 };
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


void merge_sort(std::vector <double> &list, int l, int r)
{
	if (l == r) return;
	int mid = (l + r) / 2;
	merge_sort(list, l, mid);
	merge_sort(list, mid + 1, r);
    int i = l;
    int j = mid + 1;
	std::vector <double> dop_list;
    for (int step = 0; step < r - l + 1; step++)
    {
        if ((j > r) || ((i <= mid) && (list[i] < list[j])))
        {
            dop_list.push_back(list[i]);
            i++;
        }
        else
        {
            dop_list.push_back(list[j]);
            j++;
        }
       //std::cout << '\n';
       //for (auto y : dop_list)
       //{
       //    std::cout << y << ' ';
       //}
    }
    for (int step = 0; step < r - l + 1; step++)
    {
        list[l + step] = dop_list[step];
    }
    //std::cout << '\n';
    //for (auto i : list)
    //{
    //    std::cout << i << " ";
    //}
    //std::cout << '\n';
}