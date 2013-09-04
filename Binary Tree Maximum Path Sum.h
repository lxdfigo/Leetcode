
#define NULL 0


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int path_iteration(TreeNode *node,int& maxnum)
    {
        int result = node->val;
        if (result > maxnum) maxnum = result;
        int leftvalue = 0;
        if (node->left != NULL)
        {
            leftvalue = path_iteration(node->left,maxnum);
            if (leftvalue > maxnum) maxnum = leftvalue;
        }
        int rightvalue = 0;
        if (node->right != NULL)
        {
            rightvalue = path_iteration(node->right,maxnum);
            if (rightvalue > maxnum) maxnum = rightvalue;
        }

        if (result + leftvalue + rightvalue > maxnum) maxnum = result + leftvalue + rightvalue;
        
        if (node->left != NULL && (node->right == NULL || leftvalue > rightvalue))
        {
            result += leftvalue;
        }
        if (node->right != NULL && (node->left == NULL ||  leftvalue <= rightvalue))
        {
            result += rightvalue;
        }
        return result;
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        int maxnum = -1E20;
        int result = path_iteration(root,maxnum);
        if (result > maxnum) maxnum = result;
        return maxnum;
    }
};