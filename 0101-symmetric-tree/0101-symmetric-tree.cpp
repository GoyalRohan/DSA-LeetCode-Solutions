/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true ; 
        
        queue<TreeNode*> q1 , q2 ; 
        
        q1.push(root->left) ; 
        q2.push(root->right) ; 
        
        while(!q1.empty() && !q2.empty())
        {
            TreeNode *p = q1.front() ; 
            q1.pop() ; 
            TreeNode *q = q2.front() ; 
            q2.pop() ;
            
            if(!p && !q)
                continue ; 
            if(!p || !q)
                return false ; 
            if(p->val != q->val)
                return false ; 
            
            q1.push(p->left) ; 
            q1.push(p->right) ; 
            
            q2.push(q->right) ; 
            q2.push(q->left) ; 
            
        }
        
        return true  ;
    }
};