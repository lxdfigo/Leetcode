#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i = 0; i < matrix.size(); ++i)
        {
            vector<char> &row = matrix[i];
            for(int j = 0; j < row.size(); ++j)
            {
                matrix[i][j] -=  '0';
            }
        }
        int maxr = 0;
        int rownum = 0;
        for(int i = 0; i < matrix.size(); ++i)
        {
            vector<char> &row = matrix[i];
            rownum = row.size();
            for(int j = 1; j < row.size(); ++j)
            {
                if (row[j - 1] > 0 && row[j] > 0)
                {
                    row[j] += row[j - 1];
                }
            }
        }
        for(int i = 0; i < rownum; ++i)
        {
            int len = 0;
            for(int j = 0; j < matrix.size(); ++j)
            {
                vector<char> &row = matrix[j];
                if (len == 0 || row[i] < len) len = row[i];
            }
            if (len * matrix.size() > maxr) maxr = len * matrix.size();
        }

        return maxr;
    }
};