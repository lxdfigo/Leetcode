
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
        if (left == NULL && right == NULL) return;

        TreeLinkNode* nextnode = node->next;
        while(nextnode != NULL && nextnode->left == NULL && nextnode->right == NULL)
        {
            nextnode = nextnode->next;
        }
        if (nextnode != NULL)
        {
            TreeLinkNode* prenode = right;
            if (right == NULL && left != NULL)
                prenode = left;
            if (nextnode->left != NULL)
                prenode->next = nextnode->left;
            else 
                prenode->next = nextnode->right;
        }

        if (right != NULL && left != NULL)
            left->next = right;

        if (left != NULL)
            connect_iteration(left);
        if (right != NULL)
            connect_iteration(right);
    }
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        connect_iteration(root);
    }
};