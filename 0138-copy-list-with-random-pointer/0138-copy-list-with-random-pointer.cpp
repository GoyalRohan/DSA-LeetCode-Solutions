/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    void insert(Node * &clonehead , Node * &clonetail , int x)
    {
        if(clonehead == NULL)
        {
            Node *newnode = new Node(x) ; 
            clonehead = newnode ; clonetail = newnode ; 
        }
        else
        {
            Node *newnode = new Node(x) ; 
            clonetail->next = newnode ; 
            clonetail = newnode ; 
        }
    }
    
    Node* copyRandomList(Node* head) {
        Node *orignalhead = head ; 
        Node *clonehead = NULL , *clonetail = NULL ; 
        
        Node *cur = orignalhead ;
        
        while(cur)
        {
            int x= cur->val ; 
            insert(clonehead , clonetail , x) ; 
            cur = cur->next ; 
            
        }
        
        unordered_map<Node* , Node*> mpp ;
        Node *orignalnode = orignalhead , *clonenode = clonehead ;  
        
        while(orignalnode && clonenode)
        {
            mpp[orignalnode] = clonenode ;
            orignalnode = orignalnode->next ; 
            clonenode = clonenode->next ;
        }
        
        // cout<<mpp.size() ; 
        // for (auto m : mpp)
        // {
        //     cout<<" sfs" ; 
        //     cout<<m.first->val << "->"<<m.second->val ; 
        // }
        
        orignalnode = orignalhead ; 
        clonenode = clonehead ;
        
        while(orignalnode && clonenode)
        {
            clonenode->random = mpp[orignalnode->random] ; 
            orignalnode = orignalnode->next ; 
            clonenode = clonenode->next ;
        }
        
        
        
        return clonehead ; 
        
    }
};