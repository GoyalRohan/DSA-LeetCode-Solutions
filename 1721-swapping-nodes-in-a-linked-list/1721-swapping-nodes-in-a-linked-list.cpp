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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0 ; 
        ListNode *cur = head ; 
        while(cur)
        {
            n++ ; 
            cur = cur->next ; 
        }
         
        int p = k , q = n-k , i=1 , j=0;
        ListNode *first = head , *second = head ; 
        
        while(i <p || j < q)
        {
            if(i<p && first)
            {
                first = first->next ; 
                i++; 
            }
            
            if(j<q && second)
            {
                second = second->next ; 
                j++; 
            }
        }
        
        if(first && second)
            swap(first->val , second->val) ; 
        
        return head ;
        
        
    }
};