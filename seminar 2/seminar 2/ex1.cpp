#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string str1;
	int first = 0;
	std::vector <std::string> out_format;
	str1 = "abbb-ab-a abb, a, ,   b.,. b-";
	for (int i = 0U; i < std::size(str1); ++i)
	{
		if (std::isspace(str1[i]))
		{
			if (i != first)
			{
				out_format.push_back(str1.substr(first, i - first));
			}
			first = i + 1;
		}
		else if (!std::isalpha(str1[i]))
		{
			if (i != first)
			{
				if (str1[i] == '-' && (i < std::size(str1) - 1) && isalpha(str1[i + 1]))
				{
					continue;
				}
				else
				{
					out_format.push_back(str1.substr(first, i - first));
				}
			}
			out_format.push_back(std::string(1, str1[i]));
			first = i + 1;
		}
	}
	if (std::size(str1) != first)
	{
		out_format.push_back(str1.substr(first, std::size(str1) - first));
	}
	for (int i = 0U; i < out_format.size(); ++i)
	{
		std::cout << out_format[i] << '\n';
	}
	return 0;
}