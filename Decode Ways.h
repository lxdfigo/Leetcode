#include <string>

using namespace std;

class Solution {
public:
    bool check(const string& s,int offset,int n)
    {
        if ((offset + n) > s.length() || s[offset] == '0') return false;
     
        int count = 0;
        for(int i = offset; i < offset + n; ++i)
        {
            count = count * 10 + s[i] - '0';
        }
        if (count <= 26 && count >= 1) return true;
        return false;
    }

    bool decode(const string& s,int offset,int & num)
    {
        if (offset >= s.length())
        {
            num++;
            return true;
        }
        bool sign = false;
        for(int i = 1; i <= 2; ++i)
        {
            if (check(s,offset,i))
            {
                sign |= decode(s,offset + i, num);
            }
        }
        return sign;
    }
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0) return 0;
        int num = 0;
        if (!decode(s,0,num)) return 0;
        return num;
    }
};