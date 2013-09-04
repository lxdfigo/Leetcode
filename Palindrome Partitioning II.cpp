#include <string>
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

unsigned int PalindromePartitioningII_Iteration(std::string input,unsigned int begin)
{
	if (IsPalindrome(input,begin,input.size())) return 0;

	unsigned int cutnum = input.size() - begin;
	for(unsigned int i = begin + 1; i < input.size(); ++i)
	{
		if (IsPalindrome(input,begin,i))
		{
			 unsigned int tmp = PalindromePartitioningII_Iteration(input,i) + 1;
			 if (cutnum > tmp) cutnum = tmp;
		}
	}
	return cutnum;
}

int PalindromePartitioningII(std::string input)
{
	if (input.size() == 0) return -1;
	return PalindromePartitioningII_Iteration(input,0);
}

int main()
{
	std::string str1("");
	assert(PalindromePartitioningII(str1) == -1);
	std::string str2("      ");
	assert(PalindromePartitioningII(str2) == 0);
	std::string str3("a");
	assert(PalindromePartitioningII(str3) == 0);
	std::string str4("abcdefghijklmnopqrstuvwxyz0123456789");
	assert(PalindromePartitioningII(str4) == 35);
	std::string str5("aba fe iui");
	assert(PalindromePartitioningII(str5) == 5);
	return 0;
}