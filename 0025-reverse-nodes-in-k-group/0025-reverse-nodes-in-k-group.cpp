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
        ListNode *nex ; 
        ListNode *cur = head , *prev = NULL ; 
        int cnt = 0 ; 
        
        ListNode *temp = cur ; 
        int size = 0 ; 
        while(temp)
        {
            size++ ; 
            temp = temp->next ; 
        }
        
        if(size < k)
            return head ; 
        
        while(cur != NULL && cnt<k)
        {
            nex = cur->next ; 
            cur->next = prev ; 
            prev = cur ; 
            cur = nex ; 
            cnt++ ; 
        }
        
        if(nex != NULL)
            head->next = reverseKGroup(nex , k) ;
        
        return prev ; 
        
    }
}; 