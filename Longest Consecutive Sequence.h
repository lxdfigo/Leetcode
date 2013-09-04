#include <vector>
using namespace std;

class Solution {
public:
    void setBit(vector<int> &sorted,int n)
    {
        int &sign = sorted[n >> 5];
        int offset = n & 0x1f;
        sign |= (1 << offset);
    }
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       vector<int> sorted;
       sorted.resize(128*1024*1024,0);

       unsigned min = -1;
       unsigned max = 0;
       for(unsigned int i = 0; i < num.size(); ++i)
       {
           setBit(sorted,num[i]);
           if ((num[i] >> 5) < min) min = num[i] >> 5;
           if ((num[i] >> 5) > max) max = num[i] >> 5;
       }
       long long maxcount = 0;
       long long count = -1;
       for(unsigned int i = min; i < max; ++i)
       {
           int num = sorted[i];
           for(int j = 0; j < 32; ++j)
           {
               if ((num & (1 << j)) > 0)
               {
                   count++;
               }
               else
               {
                   if (count > maxcount) maxcount = count;
                   count = -1;
               }
           }
       }
       return maxcount + 1;
    }
};