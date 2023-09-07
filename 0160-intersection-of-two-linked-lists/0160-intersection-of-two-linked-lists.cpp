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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> st1 , st2 ; 
        
        while(headA)
        {
            st1.push(headA) ; 
            headA = headA->next ; 
        }
        
        while(headB)
        {
            st2.push(headB) ; 
            headB = headB->next ; 
        }
        
        ListNode *cur = NULL , *tempA = NULL , *tempB= NULL; 
        while(!st1.empty() && !st2.empty())
        {
            tempA = st1.top() ; 
            tempB = st2.top() ; 
            st1.pop() ; 
            st2.pop() ; 
            
            if(tempA != tempB)
                break ; 
                
            cur = tempA ; 
            
            
        }
        
        return cur ; 
            
    }
};