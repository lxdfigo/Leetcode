
#define NULL 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head,int n)
    {
        ListNode* cur = head;
        ListNode* pre = cur;
        ListNode* next = cur->next;

        for(int i = 0; i < n; ++i)
        {
            cur = next;
            next = cur->next;
            cur->next = pre;
            pre = cur;
        }
        head->next = next;
        return cur;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        m--;
        n--;
        ListNode* cur = head;
        ListNode* pre = NULL;
        for(int i = 0; i < m; ++i)
        {
            pre = cur;
            cur = cur->next;
        }
        ListNode* next = reverse(cur,n - m);
        if (pre != NULL)
        {
            pre->next = next;
            return head;
        }
        else
        {
            return next;
        }
    }
};