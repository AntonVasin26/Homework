#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



std::vector< std::vector<int>> FDM(std::string str1, std::string str2)
{
	std::vector<std::vector<int>> matrix(str1.size()+1, std::vector <int>(str2.size()+1, 0));
	for (auto i = 0U; i < str1.size(); ++i)
	{
		for (auto j = 0U; j < str2.size(); ++j)
		{
			if (str1[i] == str2[j])
			{
				matrix[i+1][j+1] = matrix[i][j] + 1;
			}
			else
			{
				matrix[i+1][j+1] = std::fmax(matrix[i][j+1], matrix[i+1][j]);
			}
		}
	}
	//std::cout << "matrix_correct\n\n";
	//for (auto i = 0; i <= str1.size(); ++i)
	//{
	//	for (auto j = 0; j <= str2.size(); ++j)
	//	{
	//		std::cout << matrix[i][j] << "  ";
	//	}
	//	std::cout << '\n';
	//}
	return matrix;
}


std::string LCS_DYN(std::string str1, std::string str2)
{
	std::vector<std::vector<int>> matrix;
	std::string LCS;
	//std::cout << "program start\n\n";
	matrix = FDM(str1, str2);
	int I_str1 = str1.size(), I_str2 = str2.size();
	while (I_str1 > 0 && I_str2 > 0)
	{
		//std::cout << I_str1 << ";" << I_str2 << "\n";
		//system("pause");
		if (str1[I_str1-1] == str2[I_str2-1])
		{
			LCS.push_back(str1[I_str1-1]);
			I_str1 = I_str1 - 1;
			I_str2 = I_str2 - 1;
		}
		else if (matrix[I_str1 - 1][I_str2] > matrix[I_str1][I_str2 - 1])
		{
			I_str1 -= 1;
		}
		else
		{
			I_str2 -= 1;
		}
	}
	std::reverse(LCS.begin(), LCS.end());
	return LCS;
}


int main()
{
	std::cout << "program start\n\n";
	std::string str1 = "ab23ccd", str2 = "baa2c4cb", answer;
	answer = LCS_DYN(str1, str2);
	std::cout << "result: " << answer << "\n\n";


	return 0;
}