#include <string>

using namespace std;

class Solution {
public:
    void countSubSequence(const string& S,const string& T,int sOffset,int tOffset,int &count)
    {
        if (tOffset >= T.length())
        {
            ++count;
            return;
        }
        for(int i = sOffset; i < S.length(); ++i)
        {
            if (S[i] == T[tOffset])
            {
                countSubSequence(S,T,i+1,tOffset+1,count);
            }
        }
    }
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (T.length() > S.length() || S.length() == 0 || T.length() == 0) return 0;
        int count = 0;
        countSubSequence(S,T,0,0,count);
        return count;
    }
};