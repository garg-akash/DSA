/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
void rev(ListNode** head_ref)
{
    ListNode* prev = NULL;
    ListNode* cur = *head_ref;
    ListNode* forw = NULL;
    while(cur != NULL)
    {
        forw = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forw;
    }
    *head_ref = prev;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
            
        ListNode* current = head;    // used to iterate over the original list
        ListNode* head_rev = NULL;    // head of the new list
        ListNode* tail = NULL; 
        while (current != NULL)
        {
            // special case for the first new node
            if (head_rev == NULL)
            {
                head_rev = (struct ListNode*)malloc(sizeof(struct ListNode));
                head_rev->val = current->val;
                head_rev->next = NULL;
                tail = head_rev;
            }
            else {
                tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                tail = tail->next;
                tail->val = current->val;
                tail->next = NULL;
            }
            current = current->next;
        }
        
        
        // ListNode* head_rev = head;
        rev(&head_rev);
        // ListNode* head_rev = prev;
        while(head != NULL)
        {
            // std::cout << head->val << " ";
            
            if(head->val != head_rev->val)
                return false;
            head = head->next;
            head_rev = head_rev->next;
        }
        //     std::cout << " \nrev\n";
        // while(head_rev != NULL)
        // {
        //     std::cout << head_rev->val << " ";
        //     head_rev = head_rev->next;
        // }
        return true;
    }
};