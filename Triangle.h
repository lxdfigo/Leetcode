#include <vector>

using namespace std;

class Solution {
public:
    int search_iteration(vector<vector<int> > &triangle,int depth,int offset)
    {
        if (triangle.size() == depth) return 0;
        int res = triangle[depth][offset];

        int t1 = search_iteration(triangle,depth + 1, offset);
        int t2 = search_iteration(triangle,depth + 1, offset + 1);
        return t1 < t2 ? t1 + res : t2 + res;
    }
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return search_iteration(triangle,0,0);
    }
};