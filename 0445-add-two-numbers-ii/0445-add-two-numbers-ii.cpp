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
        ListNode *q = NULL , *p = head ; 
        while(p)
        {
            ListNode *temp = p->next ; 
            p->next = q ; 
            q = p ; 
            p = temp ; 
        }
        
        return q ; 
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL , *tail = NULL ; 
        
        stack<int> st1 , st2 ; 
        ListNode *temp = l1 ; 
        while(temp)
        {
            st1.push(temp->val) ; 
            temp = temp->next ; 
        }
        
        temp = l2; 
        while(temp)
        {
            st2.push(temp->val) ; 
            temp = temp->next ; 
        }
        
        int carry = 0 ; 
        while(!st1.empty() || !st2.empty() || carry)
        {
            int sum = 0 ; 
            if(!st1.empty())
            {
                sum += st1.top() ; 
                st1.pop() ; 
            }
            if(!st2.empty())
            {
                sum += st2.top() ; 
                st2.pop() ; 
            }
            
            sum += carry ; 
            
            int rem = sum%10 ; 
            carry = sum/10 ; 
            
            ListNode *newnode = new ListNode(rem) ; 
            if(head == NULL)
                head = tail = newnode ; 
            else
            {
                tail->next = newnode ; 
                tail = tail->next ; 
            }
        }
        
        head = reverse(head) ; 
        return head ; 
    }
};