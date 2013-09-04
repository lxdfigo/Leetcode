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
    void travel_iteration(TreeNode*node,vector<int> &result)
    {
        if (node->left != NULL)
            travel_iteration(node->left,result);
        result.push_back(node->val);
        if (node->right != NULL)
            travel_iteration(node->right,result);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        if (root == NULL) return result;
        travel_iteration(root,result);
        return result;
    }
};