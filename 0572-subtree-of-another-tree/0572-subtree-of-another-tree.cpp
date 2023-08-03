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
    
    vector<TreeNode*> nodes ; 
    
    void findSubNode(TreeNode *root, TreeNode* subRoot )
    {
        if(root == NULL)
            return  ; 
        
        if(root->val == subRoot->val)
        {
            nodes.push_back(root) ;  
        }
        
        
        findSubNode (root->left , subRoot) ; 
        findSubNode (root->right , subRoot) ; 
        
    }
    
    bool checkTree(TreeNode *sub, TreeNode *subRoot)
    {
        if(!sub || !subRoot)
            return sub == subRoot ; 
        
        return (sub->val == subRoot->val) && checkTree(sub->left , subRoot->left) &&  checkTree(sub->right , subRoot->right) ; 
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        findSubNode (root , subRoot) ; 

        for(auto *n : nodes)
        {
            if(checkTree(n , subRoot))
                return true ; 
        }

        return false ; 
    }
};