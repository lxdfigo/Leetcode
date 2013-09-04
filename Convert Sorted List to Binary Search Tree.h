
#define NULL 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    ListNode *getNode(ListNode*head,int offset)
    {
        while(offset-- > 1)
            head = head->next;            
        return head;
    }
    TreeNode *buildTree(ListNode *head,int count)
    {
        if (count == 1)
        {
            return new TreeNode(head->val);
        }
        int mid = count >> 1;
        ListNode *node = getNode(head,mid);
        TreeNode *treeNode = new TreeNode(node->next->val);
        if (node->next->next != NULL)
        {
            TreeNode *right = buildTree(node->next->next,(mid + (count & 1) - 1));
            treeNode->right = right;
        }
        node->next = NULL;
        TreeNode *left = buildTree(head,mid);
        treeNode->left = left;
        return treeNode;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        ListNode *node = head;
        int count = 0;
        while(node != NULL)
        {
            node = node->next;
            count ++;
        }
        return buildTree(head,count);
    }
};