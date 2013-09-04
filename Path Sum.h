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
    bool path_iteration(vector<int> path,TreeNode *node,int sum)
    {
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL)
        {
            int count = 0;
            for(int i = 0; i < path.size(); ++i)
            {
                count += path[i];
            }
            if (count == sum)
            {
                return true;
            }
            return false;
        }
        if (node->left != NULL && path_iteration(path,node->left,sum))
            return true;

        if (node->right != NULL && path_iteration(path,node->right,sum))
            return true;

        return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return false;
        vector<int> path;
        return path_iteration(path,root,sum);        
    }
};