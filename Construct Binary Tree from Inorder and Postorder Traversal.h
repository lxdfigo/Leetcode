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

    TreeNode *buildTree_iteration(vector<int> &inorder,int begin,int end,vector<int> &postorder,int& poffset)
    {
        if (begin == end - 1)
        {
            return new TreeNode(inorder[begin]);
        }
        int mid = findpos(inorder,begin,end,postorder[poffset]);
        TreeNode *node = new TreeNode(inorder[mid]);
        if (mid + 1 < end)
            node->right = buildTree_iteration(inorder,mid + 1,end,postorder,--poffset);
        if (begin < mid)
            node->left = buildTree_iteration(inorder,begin,mid,postorder,--poffset);

        return node;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.size() == 0) return NULL;
        int offset = postorder.size() - 1;
        return buildTree_iteration(inorder,0,inorder.size(),postorder,offset);
    }
};