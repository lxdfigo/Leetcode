/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
    TreeNode *buildTree(vector<int> &vec,int begin,int end)
    {
        if (begin == end)
        {
            return new TreeNode(vec[begin]);
        }
        int mid = (end + begin) >> 1;

        TreeNode *treeNode = new TreeNode(vec[mid]);


        if (begin <= mid - 1)
        {
            TreeNode *left = buildTree(vec,begin,mid - 1);
            treeNode->left = left;
        }

        TreeNode *right = buildTree(vec,mid+1, end);
        treeNode->right = right;
        return treeNode;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() == 0) return NULL;

        return buildTree(num,0,num.size() - 1);
    }
};