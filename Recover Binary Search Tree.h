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
    TreeNode * getStart(TreeNode *node)
    {
        TreeNode *start = node;
        while(start->left != NULL)
        {
            start = start->left;
        }
        return start;
    }
    void search_iteration(TreeNode *node,TreeNode **first,TreeNode **second,TreeNode **begin,TreeNode **end)
    {
        *begin = node;
        *end = node;
        if (node->left != NULL)
        {
            TreeNode *start, *tail;
            search_iteration(node->left,first,second,&start,&tail);
            if (tail->val > node->val)
            {
                if (*first == NULL)
                {
                    *first = tail;
                }
                *second = node;
            }
            *begin = start;
        }

        if (node->right != NULL)
        {
            TreeNode *start, *tail;
            start = getStart(node->right);
            if (node->val > start->val)
            {
                if (*first == NULL)
                {
                    *first = node;
                }
                *second = start;
            }
            search_iteration(node->right,first,second,&start,&tail);
            *end = tail;
        }
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode *begin, *end;
        search_iteration(root,&first,&second,&begin,&end);
        int tmp = (first)->val;
        (first)->val = (second)->val;
        (second)->val = tmp;

        return;
    }
};