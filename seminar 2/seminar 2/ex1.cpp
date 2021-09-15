#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string str1;
	int s = 0;
	std::vector <std::string> out_format;
	std::getline(std::cin, str1);
	for (int i = 0U; i < str1.size(); ++i)
	{
		if (str1[i] == ' ')
		{
			if (i != s)
			{
				out_format.push_back(str1.substr(s, i - s));
			}
			s = i + 1;
		}
		else if (20 < char(str1[i]) && char(str1[i]) < 64)
		{
			if (i != s)
			{
				if (char(str1[i]) == char('-') && 
					(i < str1.size() - 1) && !(19 < char(str1[i + 1]) && char(str1[i + 1]) < 64))
				{
					continue;
				}
				else
				{
					out_format.push_back(str1.substr(s, i - s));
				}
			}
			out_format.push_back(str1.substr(i, 1));
			s = i + 1;
		}
	}
	if (str1.size() - s != 0)
	{
		out_format.push_back(str1.substr(s, str1.size() - s));
	}
	for (int i = 0U; i < out_format.size(); ++i)
	{
		std::cout << out_format[i] << '\n';
	}
	return 0;
}

