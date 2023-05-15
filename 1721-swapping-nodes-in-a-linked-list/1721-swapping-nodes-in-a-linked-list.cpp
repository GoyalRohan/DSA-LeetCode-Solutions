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

        
        int  i=1 ; 
        ListNode *first = head , *second = head , *kth = NULL; 
        
        while(i <k )
        {
            first = first->next ; 
            i++; 
        }
        
        kth = first ; 
        first = first->next ; 
        
        while(first)
        {
            first = first->next ; 
            second = second->next ; 
        }
        
        
        swap(kth->val , second->val) ; 
        
        return head ;
        
        
    }
};