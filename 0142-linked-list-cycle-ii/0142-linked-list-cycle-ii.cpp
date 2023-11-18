/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return head ; 
        
        ListNode *slow = head , *fast = head ; 
        
        while(fast && fast->next)
        {
            slow = slow->next ; 
            fast = fast->next->next ; 
            
            if(slow == fast)
                break ; 
        }
        
        if(!fast || !fast->next)
            return NULL ; 
        
        ListNode *ptr1 = head , *ptr2 = slow ; 
        
        while(ptr1 != ptr2)
        {
            ptr1 = ptr1->next ; 
            ptr2 = ptr2->next ; 
        }
        
        return ptr1 ; 
    }
};