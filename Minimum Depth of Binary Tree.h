/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void path_iteration(TreeNode *node,unsigned int depth,unsigned int& mindepth)
    {
        if (node->left == NULL && node->right == NULL)
        {
            if (depth < mindepth)
            {
                mindepth = depth;
            }
            return ;
        }
        if (node->left != NULL)
            path_iteration(node->left,depth + 1,mindepth);

        if (node->right != NULL)
            path_iteration(node->right,depth + 1,mindepth);

        return ;
    }
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        unsigned int minDepth = -1;
        path_iteration(root,1,minDepth);
        return minDepth;
    }
};