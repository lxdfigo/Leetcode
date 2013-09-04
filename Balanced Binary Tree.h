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
    bool getDepth_iteration(TreeNode *node,int& depth)
    {
        if (node->left == NULL && node->right == NULL)
        {
            return true;
        }
        int ld = depth;
        if (node->left != NULL && !getDepth_iteration(node->left,++ld))
        {
            return false;
        }

        int rd = depth;
        if (node->right != NULL && !getDepth_iteration(node->right,++rd))
        {
            return false;
        }
        if ((rd - ld) > 1 || (rd - ld) < -1)
            return false;
        
        depth = ld > rd ? ld : rd;
        return true;
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return true;
        int depth = 1;
        return getDepth_iteration(root,depth);
    }
};