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
    int findpos(vector<int> &inorder,int begin,int end,int num)
    {
        for(int i  = begin; i < end; ++i)
        {
            if (inorder[i] == num) return i;
        }
        return -1;
    }

    TreeNode *buildTree_iteration(vector<int> &inorder,int begin,int end,vector<int> &preorder,int& poffset)
    {
        if (begin == end - 1)
        {
            return new TreeNode(inorder[begin]);
        }
        int mid = findpos(inorder,begin,end,preorder[poffset]);
        TreeNode *node = new TreeNode(inorder[mid]);
        
        if (begin < mid)
            node->left = buildTree_iteration(inorder,begin,mid,preorder,++poffset);
        if (mid + 1 < end)
            node->right = buildTree_iteration(inorder,mid + 1,end,preorder,++poffset);

        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.size() == 0) return NULL;
        int offset = 0;
        return buildTree_iteration(inorder,0,inorder.size(),preorder,offset);
    }
};