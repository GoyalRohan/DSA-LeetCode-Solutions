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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head || !head->next)
            return head ; 
        
        ListNode *oddstart = head , *evenstart = head->next ;    
        ListNode *curodd = oddstart , *cureven = evenstart ; 
        
        while(curodd->next && cureven->next)
        {

                curodd->next = cureven->next ; 
                curodd = curodd->next ; 
            
 
                cureven->next = curodd->next ; 
                cureven = cureven->next ; 
        }
        
        curodd->next = evenstart ; 
        
        return oddstart ; 
    }
};