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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return true;
        vector<TreeNode*> stack;
        stack.push_back(root);

        while(!stack.empty())
        {
            for(int i = 0; i < (stack.size() >> 1); ++i)
            {
                if ((stack[i] != NULL && stack[stack.size() - i - 1] != NULL && stack[i]->val != stack[stack.size() - i - 1]->val)
                    || (stack[i] != NULL && stack[stack.size() - i - 1] == NULL )
                    || (stack[i] == NULL && stack[stack.size() - i - 1] != NULL))
                    return false;
            }

            vector<TreeNode*> tmpstack;
            for(int i = 0; i < stack.size(); ++i)
            {
                if (stack[i] != NULL)
                {
                    tmpstack.push_back(stack[i]->left);
                    tmpstack.push_back(stack[i]->right);
                }
            }
            stack.clear();
            stack.resize(tmpstack.size());
            for(int i = 0; i < tmpstack.size(); ++i)
            {
                stack[i] = tmpstack[i];
            }
        }
        return true;
    }
};