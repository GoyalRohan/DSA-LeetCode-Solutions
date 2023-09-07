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
class Solution {
public:
    
    ListNode *reverse(ListNode *ptr)
    {
        ListNode* pre=NULL;
        ListNode* nex=NULL;
        while(ptr!=NULL) {
            nex = ptr->next;
            ptr->next = pre;
            pre=ptr;
            ptr=nex;
        }
       return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true ; 
        
        ListNode *slow = head , *fast = head ; 
        
        while(fast && fast->next && fast->next->next)
        {
            fast = fast->next->next ; 
            slow = slow->next ; 
        }
        
        slow->next = reverse(slow->next) ; 
        slow = slow->next ; 
        
        ListNode *temp = head ; 
        
        while(slow)
        {
            if(temp->val != slow->val)
                return false ; 
            
            temp = temp->next ; 
            slow = slow->next ; 
        }
        
        return true ; 
        
    }
};