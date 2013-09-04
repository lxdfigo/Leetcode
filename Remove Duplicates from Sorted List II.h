
#define NULL 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * cur = head;
        while(cur != NULL)
        {
            ListNode * cmp = head;
            bool sign = false;
            while(cmp != cur)
            {
                if (cmp->val == cur->val)
                {
                    sign = true;
                    break;
                }
                cmp = cmp->next;
            }

            // remove all same node
            if (sign == true)
            {
                int v = cur->val;
                ListNode* rm = head;
                ListNode* pre = NULL;
                while(rm != NULL)
                {
                    if (rm->val == v)
                    {
                        if (pre != NULL)
                        {
                            pre->next = rm->next;
                            delete rm;
                            rm = pre->next;
                        }
                        else
                        {
                            head = head->next;
                            delete rm;
                            rm = head;
                        }
                    }
                    else
                    {
                        pre = rm;
                        rm = rm->next;
                    }
                }
                cur = head;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
};