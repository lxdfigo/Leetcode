#include <string>

using namespace std;

class Solution {
public:
    bool checkLetter(char c)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        for(unsigned int i = 0; i < s.length(); ++i)
        {
            if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
        }
        int begin = 0;
        int end = s.length()-1;
        while(end > begin)
        {
            while(!checkLetter(s[begin]) && begin < end) ++begin;
            while(!checkLetter(s[end]) && begin < end) --end;
            if (begin < end && s[begin] != s[end])
                return false;
            ++begin;
            --end;
        }
        return true;
    }
};