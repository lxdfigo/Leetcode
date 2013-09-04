
#define NULL 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *cur = head;
        ListNode *pre = NULL;
        ListNode *before = NULL;
        while(cur != NULL)
        {
            if (cur->val < x)
            {
                before = cur;
                pre = cur;
                cur = cur->next;
            }
            else
            {
                break;
            }
        }
        while(cur != NULL)
        {
            if (cur->val < x)
            {
                ListNode * tmp = cur->next;
                if (pre != NULL)  pre->next = cur->next;
                else pre = cur;
                if (before == NULL)
                {
                    before = cur;
                    if (cur != head)
                    {
                        cur->next = head;
                        head = cur;
                    }
                }
                else
                {
                    cur->next = before->next;
                    before->next = cur;
                    before = before->next;
                }
                cur = tmp;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};