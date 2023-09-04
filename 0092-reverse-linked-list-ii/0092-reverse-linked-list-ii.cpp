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
    
    ListNode *reverse(ListNode *temp , int right, int pos)
    {
        ListNode *r = temp ; 
        ListNode *q = NULL , *p = NULL; 
        while(r && pos <= right)
        {
            q = r->next ; 
            r->next = p ; 
            
            p = r ; 
            r = q ; 
            
            pos++ ; 
        }
        
        temp->next = r ; 
        return p ; 
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp = head; 
        int pos = 0 ; 
        if(!head || !head->next)
            return head ; 
        
        ListNode *dummy = new ListNode(-1) ; 
        dummy->next = head ; 
        ListNode *p = dummy ; 
        
        while(temp)
        {
            pos++ ; 
            if(pos == left)
            {
                
                p->next = reverse( temp , right , pos) ; 
                
                break ; 
            }
            
            p = temp ; 
            temp = temp->next ; 
        }
        
        return dummy->next ; 
    }
};