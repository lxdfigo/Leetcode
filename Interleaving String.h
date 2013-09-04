#include <string>

using namespace std;

class Solution {
public:
    bool match_iteration(const string& s1,int off1,const string& s2,int off2,const string& s3,int off3)
    {
        if (off3 >= s3.length())
        {
            if (off2 >= s2.length() && off1 >= s1.length())
                return true;
            else
                return false;
        }
        if (s1[off1] == s3[off3])
        {
            if (match_iteration(s1,off1+1,s2,off2,s3,off3+1)) return true;
        }
        if (s2[off2] == s3[off3])
        {
            if (match_iteration(s1,off1,s2,off2+1,s3,off3+1)) return true;
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        return match_iteration(s1,0,s2,0,s3,0);
    }
};