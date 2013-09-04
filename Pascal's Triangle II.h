#include <vector>

using namespace std;


class Solution {
public:
    void get_iteration(vector<int>& lastrow,int depth,int targetDepth)
    {
        if (depth >= targetDepth) return;
        for(int i = depth - 1; i > 0; --i)
        {
            lastrow[i] += lastrow[i - 1];
        }
        lastrow[depth] = 1;
        get_iteration(lastrow,depth+1,targetDepth);
    }
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ++rowIndex;
        vector<int> output;
        output.resize(rowIndex,0);
        output[0] = 1;
        get_iteration(output,1,rowIndex);
        return output;
    }
};