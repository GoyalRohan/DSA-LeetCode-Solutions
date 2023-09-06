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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head ; 
        
        ListNode *dummy = new ListNode(-1) ; 
        dummy->next = head ; 
        ListNode *r = dummy ; 
        ListNode *p = head , *q = head->next ;  
        
        while(q)
        {
            if(q->val != p->val)
            {
                r = p ; 
                p = q ; 
                q = q->next ; 
            }
            else
            {
                while(q && p->val == q->val)
                {
                    p = q ;
                    q = q->next ; 
                }
                
                r->next = q ; 
                p = q ; 
                if(q)
                    q = q->next ; 
            }
        }
        
        return dummy->next ; 
        
    }
};