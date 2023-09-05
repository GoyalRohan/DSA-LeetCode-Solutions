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
    ListNode* partition(ListNode* head, int x) {
        
         ListNode lessDummy(0); // Dummy node for nodes less than x
    ListNode greaterDummy(0); // Dummy node for nodes greater than or equal to x
    
    ListNode* lessPtr = &lessDummy;
    ListNode* greaterPtr = &greaterDummy;
    
    while (head) {
        if (head->val < x) {
            lessPtr->next = head;
            lessPtr = lessPtr->next;
        } else {
            greaterPtr->next = head;
            greaterPtr = greaterPtr->next;
        }
        head = head->next;
    }
    
    lessPtr->next = greaterDummy.next; // Connect less list to greater list
    greaterPtr->next = nullptr; // Mark the end of the combined list
    
    return lessDummy.next; 
    }
};