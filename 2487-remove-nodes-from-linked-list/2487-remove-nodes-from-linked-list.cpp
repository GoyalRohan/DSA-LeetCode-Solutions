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
    
    ListNode *reverse(ListNode *head)
    {
        ListNode *p = NULL , *q = head ; 
        while(q)
        {
            ListNode *nex = q->next ; 
            q->next = p ; 
            p = q ; 
            q = nex ; 
        }
        return p ; 
    }
    
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next)
            return head ;
            
        head = reverse(head) ; 
        int last = INT_MIN ; 
        ListNode *cur = head , *prev = NULL; 
        
        while(cur)
        {
            if(cur->val >= last)
            {
                last = cur->val ; 
                prev = cur ; 
                cur = cur->next ; 
            }
            else
            {
                prev->next = cur->next ; 
                cur = cur->next ; 
            }
        }
        
        head = reverse(head); 
        
        return head ; 
    }
};