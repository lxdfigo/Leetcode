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
    void path_iteration(vector<int> path,TreeNode *node,int sum,vector<vector<int> > & result)
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
                result.push_back(path);
            }
            return;
        }
        if (node->left != NULL)
            path_iteration(path,node->left,sum,result);

        if (node->right != NULL)
            path_iteration(path,node->right,sum,result);

    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if (root == NULL) return result;
        vector<int>path;
        path_iteration(path,root,sum,result);
        return result;
    }
};