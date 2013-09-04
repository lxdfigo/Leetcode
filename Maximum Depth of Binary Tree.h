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
    void depth_iteration(TreeNode *node,int depth, int &maxdepth)
    {
        if (depth > maxdepth) maxdepth = depth;
        if (node->left != NULL)
            depth_iteration(node->left,depth+1,maxdepth);
        if (node->right != NULL)
            depth_iteration(node->right,depth+1,maxdepth);
    }
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        int maxd  = 0;
        depth_iteration(root,1,maxd);
        return maxd;
    }
};