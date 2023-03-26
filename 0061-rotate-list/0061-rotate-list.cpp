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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head ; 
        
        int size = 0; 
        ListNode *p = head ; 
        
        while(p->next)
        {
            size++ ; 
            p = p->next ; 
        }
        size++ ; 
        
        k = k%size ; 
        if(k == 0 )
            return head; 
        
        int i = 1 ;
        ListNode *temp = head ; 
        for(i=1 ; i<size-k && temp != NULL ; i++)
        {
            temp = temp->next ; 
        }
        
        ListNode *newhead = temp->next ; 
        temp->next = NULL ; 
        p->next = head ; 
        head = newhead ;
        
        return head ; 
        
        
    }
};