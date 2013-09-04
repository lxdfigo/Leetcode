#include <string>
#include <vector>
#include <assert.h>

bool IsPalindrome(std::string input,unsigned int begin,unsigned int end)
{
	assert(end > begin);
	int len = (end - begin) >> 1;
	for(int i = 0; i < len; ++i)
	{
		if (input[begin + i] != input[end - i - 1])
			return false;
	}
	return true;
}

std::vector<std::vector<std::string> > PalindromePartitioning_Iteration(std::string input,unsigned int begin)
{
	std::vector<std::vector<std::string> > vecStrings;

	for(unsigned int i = input.size(); i >= begin + 1; --i)
	{
		if (IsPalindrome(input,begin,i))
		{
			std::string str = input.substr(begin,i - begin);	
			if (i == input.size())
			{
				std::vector<std::string> vec;
				vec.push_back(str);
				vecStrings.push_back(vec);
			}
			else
			{
				std::vector<std::vector<std::string> >& tmp = PalindromePartitioning_Iteration(input,i);
				for(unsigned int k = 0; k < tmp.size(); ++k)
				{
					std::vector<std::string>& vec = tmp[k];
					vec.insert(vec.begin(),str);
					vecStrings.push_back(vec);
				}
			}
		}
	}
	return vecStrings;
}

std::vector<std::vector<std::string> > PalindromePartitioning(std::string input)
{
	if (input.size() == 0) return std::vector<std::vector<std::string> >();
	return PalindromePartitioning_Iteration(input,0);
}