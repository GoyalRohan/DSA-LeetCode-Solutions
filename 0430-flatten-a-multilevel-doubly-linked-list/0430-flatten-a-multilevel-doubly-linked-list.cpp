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
        
        Node *cur = head ,  *nex , *temp; 
        
        while(cur)
        {
            if(cur->child)
            {
                nex  = cur->next ; 
                cur->next = cur->child ; 
                cur->next->prev = cur ; 
                cur->child = NULL ; 
                
                Node *temp = cur->next ; 
                while(temp->next)
                    temp = temp->next ; 
                temp->next = nex ; 
                if(nex)
                    nex->prev = temp ; 
                
            }
            cur = cur->next ;
        }
        
        return head ; 
    }
};