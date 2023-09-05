/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return NULL ; 
        
        Node *cur = head ; 
        while(cur)
        {
            if(cur->child == NULL)
            {
                cur = cur->next ; 
            }
            else
            {
                Node *nex = cur->next ; 
                cur->next = flatten(cur->child) ; 
                cur->next->prev= cur ; 
                Node *temp = cur->next ; 
                
                while(temp->next)
                {
                    temp = temp->next ; 
                }
                
                temp->next = nex ; 
                if(nex)
                    nex->prev = temp ; ;
                cur->child = NULL ; 
                cur = nex ; 
                
            }
        }
        
        return head ; 
    }
};