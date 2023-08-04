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
    
    bool solve(TreeNode *root , long minval , long maxval)
    {
        if(root == NULL)
           return true  ; 
           
        bool left = solve(root->left , minval , root->val) ; 
        bool right = solve(root->right , root->val , maxval) ; 
        
        if(root->val > minval && root->val < maxval && left && right)
            return true ; 
        
        return false ; 
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true ; 
        
        return solve(root , LONG_MIN , LONG_MAX) ; 
        
    }
};