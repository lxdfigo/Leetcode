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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (p == NULL && q == NULL) return true;
        if (p == NULL && q != NULL || p != NULL && q == NULL) return false;
        if (p->val != q->val) return false;

        if (!isSameTree(p->left,q->left)) return false;
        if (!isSameTree(p->right,q->right)) return false;
        return true;
    }
    void generate_iteration(TreeNode *prenode,TreeNode *root,int isleaf,int begin,int end,vector<int> &vec,vector<TreeNode *> & results)
    {
        if (begin == end)
        {
            for(int i = 0; i < results.size(); ++i)
            {
                if (isSameTree(results[i],root)) return;
            }
            results.push_back(root);
            return;
        } 
        TreeNode* node = new TreeNode(vec[begin]);

        switch(isleaf)
        {  
        case 0:
            node->left = prenode;
            generate_iteration(node,node,0,begin + 1,end,vec,results);
        case 1:
            prenode->right = node;
            generate_iteration(node,prenode,1,begin + 1,end,vec,results);
            generate_iteration(prenode,prenode,2,begin + 1,end,vec,results);
            generate_iteration(prenode,prenode,3,begin + 1,end,vec,results);          
            break;
        case 2:
            node->left = prenode;
            generate_iteration(node,node,0,begin + 1,end,vec,results);
            break;
        case 3:
            node->left = prenode->right;
            prenode->right = node;
            generate_iteration(node,prenode,1,begin + 1,end,vec,results);
            generate_iteration(prenode,prenode,3,begin + 1,end,vec,results);
            break;
        }

        return;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<TreeNode *> results;
        if (n == 0) return results;

        vector<int> vec;
        vec.resize(n);
        for(int i = 0; i < vec.size(); ++i)
        {
            vec[i] = i+1;
        }
        TreeNode* node = new TreeNode(vec[0]);
        generate_iteration(node,node,0,1,vec.size(),vec,results);
        return results;
    }
};