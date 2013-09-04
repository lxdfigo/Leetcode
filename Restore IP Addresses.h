#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkIsValid(const string &str)
    {
        int count = 0;
        if (str.length() > 1 && str[0] == '0') return false;
        for(int i = 0; i < str.length(); ++i)
        {
            count = count * 10 + (str[i] - '0');
        }
        if (count <= 255)
            return true;
        else
            return false;
    }
    void check_iteration(const string & s, int offset, int depth, string cur,vector<string> & result)
    {
        if (depth > 4) return;
        if (depth == 4 && s.length() == offset)
        {
            result.push_back(cur);
            return;
        }

        for(int i = 1; i <= 3; ++i)
        {
            if (offset + i > s.length()) return;
            string substr = s.substr(offset,i);
            if (checkIsValid(substr))
            {
                string tmp = cur;
                if (!tmp.empty()) tmp.append(".");
                tmp.append(substr);
                check_iteration(s,offset + i,depth + 1,tmp,result);                
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ipadresses;
        if (s.length() < 4) return ipadresses;
        string cur;
        check_iteration(s,0,0,cur,ipadresses);
        return ipadresses;

    }
};