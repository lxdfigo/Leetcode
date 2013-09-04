
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
    bool search_iteration(TreeNode *node,TreeNode **begin,TreeNode **end)
    {
        *begin = node;
        *end = node;
        if (node->left != NULL)
        {
            TreeNode *start, *tail;
            if (!search_iteration(node->left,&start,&tail)) return false;
            if (tail->val >= node->val)
            {
                return false;
            }
            *begin = start;
        }

        if (node->right != NULL)
        {
            TreeNode *start, *tail;
            if (!search_iteration(node->right,&start,&tail)) return false;
            if (node->val >= start->val)
            {
                return false;
            }
            *end = tail;
        }
        return true;
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        if (root == NULL) return true;
        TreeNode *begin, *end;
        return search_iteration(root,&begin,&end);
    }
};