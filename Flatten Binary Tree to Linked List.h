#define NULL 0

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *flatten_iteration(TreeNode *node)
    {

        TreeNode *lend = NULL;
        TreeNode *rend = NULL;
        if (node->left != NULL)
            lend = flatten_iteration(node->left);
        if (node->right != NULL)
            rend = flatten_iteration(node->right);

        if (node->left != NULL)
        {
            lend->right = node->right;
            lend->left = NULL;
            node->right = node->left;
        }
        node->left = NULL;
        if (rend != NULL)
            return rend;
        if (lend != NULL)
            return lend;
        return node;
    }

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        flatten_iteration(root);
    }
};