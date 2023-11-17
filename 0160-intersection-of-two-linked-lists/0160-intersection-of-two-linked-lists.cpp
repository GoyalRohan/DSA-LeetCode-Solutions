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
//         int a = 0 , b= 0 ;
        
//         ListNode *cur = headA ; 
//         while(cur)
//         {
//             a++ ; 
//             cur = cur->next ; 
//         }
        
//         cur= headB ; 
//         while(cur)
//         {
//             b++ ; 
//             cur = cur->next ; 
//         }
        
//         int diff = abs(a - b) ; 
        
//         if(a < b)
//         {
//             while(diff--)
//                 headB = headB->next ; 
//         }
//         else
//         {
//             while(diff--)
//                 headA = headA->next ;
//         }
        
//         while(headA && headB)
//         {
//             if(headA == headB)
//             {
//                 return headA ; 
//             }
            
//             headA = headA->next ; 
//             headB = headB->next ; 
//         }
        
//         return NULL ; 
        
        unordered_set<ListNode*> uset ; 
        ListNode *temp = headA ;
        
        while(temp)
        {
            uset.insert(temp) ; 
            temp = temp->next ; 
        }
        
        
        temp = headB ; 
        while(temp)
        {
            if(uset.find(temp) != uset.end())
                return temp ; 
            else
                temp = temp->next ; 
        }
        
        return NULL ; 
        
        
    }
};