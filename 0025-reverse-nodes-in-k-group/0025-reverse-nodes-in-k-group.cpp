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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0 ; 
        ListNode *cur = head ; 
        
        while(cur)
        {
            cnt++ ; 
            cur = cur->next ; 
        }
        if(cnt < k)
            return head ; 
        
        cnt = 0 ; 
        ListNode *p = head , *q = NULL ; 
        
        while(cnt<k && p)
        {
            ListNode *nex = p->next ; 
            p->next = q ; 
            q = p; 
            p = nex ; 
            
            cnt++ ; 
        }
        
        if(p)
            head->next = reverseKGroup(p , k) ; 
        
        return q ; 
    }
};