#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > result;
        if (numRows < 0) return result;
        vector<int> lastrow;
        for(int depth = 0; depth < numRows; ++depth)
        {
            for(int i = depth - 1; i > 0; --i)
            {
                lastrow[i] += lastrow[i - 1];
            }
            lastrow.push_back(1);
            result.push_back(lastrow);
        }
        return result;
    }
};