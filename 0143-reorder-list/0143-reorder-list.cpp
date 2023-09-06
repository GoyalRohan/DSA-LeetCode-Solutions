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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec ; 
        ListNode *cur = head ; 
        
        while(cur)
        {
            vec.push_back(cur) ; 
            cur = cur->next ; 
        }
        
        int l=0 , r = vec.size()-1; 
        
        while(l < r)
        {
            vec[l++]->next = vec[r] ; 
            vec[r--]->next = vec[l] ; 
        }
        
        vec[l]->next = NULL ; 
    }
};