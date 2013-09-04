
#define NULL 0

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect_iteration(TreeLinkNode *node)
    {
        TreeLinkNode* left = node->left;
        TreeLinkNode* right = node->right;
        if (left == NULL) return;
        left->next = right;
        if (node->next != NULL)
        {
            right->next = node->next->left;
        }
        connect_iteration(left);
        connect_iteration(right);
    }
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        connect_iteration(root);
    }
};