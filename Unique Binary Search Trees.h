#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int compute(int n,vector<int> & memo)
    {
        if (memo[n] != 0) return memo[n];
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            count += compute(n-1 - i,memo) * compute(i,memo);
        }
        memo[n] = count;
        return memo[n];
    }
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> memo;
        memo.resize(n + 1,0);
        memo[0] = 1;
        memo[1] = 1;
        return compute(n,memo);
    }
};