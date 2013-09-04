
#define NULL 0

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int acceTreeNode(TreeNode *node,int &befornum)
    {
        if (node == 0) return befornum;
        befornum = befornum * 10 + node->val;
        if (node->left == NULL && node->right == NULL) return befornum;
        
        int sum = 0;
        int leftbefornum = befornum;
        int rightbefornum = befornum;
        if (node->left != NULL)
            sum += acceTreeNode(node->left,leftbefornum);
        if (node->right != NULL)
            sum += acceTreeNode(node->right,rightbefornum);
        return sum;
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        return acceTreeNode(root,sum);
    }
};