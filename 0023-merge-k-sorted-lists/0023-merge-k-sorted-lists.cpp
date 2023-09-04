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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int ,ListNode*> , vector<pair<int ,ListNode*>> , greater<pair<int ,ListNode*>>> pq ; 
        
        for(int i=0 ; i<lists.size() ; i++)
        {
            ListNode *temp = lists[i] ; 
            if(temp)
                pq.push({temp->val , temp}) ; 
        }
        
        ListNode *dummy = new ListNode() ;
        ListNode *tail = dummy ; 
        
        while(!pq.empty())
        {
            auto it = pq.top() ; 
            pq.pop() ; 
            ListNode *node = it.second ; 
            tail->next = node ; 
            tail = tail->next ; 
            
            if(node->next)
            {
                pq.push({node->next->val , node->next}) ; 
            }
        }
        
        return dummy->next ; 
    }
};