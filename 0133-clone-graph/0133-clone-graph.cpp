/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    void dfs(Node *cur , Node *node , vector<Node*> &vis)
    {
        vis[cur->val] = node ; 
        for(auto ele : cur->neighbors)
        {
            if(vis[ele->val] == NULL)
            {
                Node *newnode = new Node(ele->val) ; 
                node->neighbors.push_back(newnode) ; 
                dfs(ele , newnode , vis) ; 
            }
            else
                node->neighbors.push_back(vis[ele->val]) ; 
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node ; 
        
        vector<Node*> vis(101 , NULL) ; 
        Node *copy = new Node(node->val)  ;
        vis[node->val] = copy ; 
        
        for(auto ele : node->neighbors)
        {
            if(vis[ele->val] == NULL)
            {
                Node *newnode = new Node(ele->val) ; 
                copy->neighbors.push_back(newnode) ; 
                dfs(ele , newnode , vis) ; 
            }
            else
                copy->neighbors.push_back(vis[ele->val]) ; 
        }
        
        return copy ; 
    }
};