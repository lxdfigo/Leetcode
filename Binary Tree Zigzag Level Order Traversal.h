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
    void insert_iteration(vector<vector<TreeNode* > >& levels)
    {
        vector<TreeNode* > &row = levels[levels.size() - 1];

        vector<TreeNode* > newrow;
        for(int i = 0 ; i < row.size(); ++i)
        {
            if (row[i]->left != NULL) newrow.push_back(row[i]->left);
            if (row[i]->right != NULL) newrow.push_back(row[i]->right);
        }
        if (newrow.size() > 0)
        {
            levels.push_back(newrow);
            insert_iteration(levels);
        }
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<int> > result;
        if (root == NULL) return result;
        vector<vector<TreeNode* > > levels;
        vector<TreeNode*> row;
        row.push_back(root);
        levels.push_back(row);
        insert_iteration(levels);

        int count = 0;
        for(int i = 0; i < levels.size(); ++i)
        {
            vector<TreeNode*> &row = levels[i];
            vector<int> tmp;
            if (count % 2 == 0)
            {
                for(int j = 0; j < row.size(); ++j)
                {
                    tmp.push_back(row[j]->val);
                }
            }
            else
            {
                for(int j = row.size() - 1; j >= 0; --j)
                {
                    tmp.push_back(row[j]->val);
                }
            }
            result.push_back(tmp);
            count++;
        }
    }
};