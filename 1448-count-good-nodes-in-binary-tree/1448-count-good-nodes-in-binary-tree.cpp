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
    
    int count = 0 ;
    void solve(TreeNode* root , int maxval)
    {
        if(!root)
            return ; 
        
        
        if(root->val >= maxval)
        {
            count++ ; 
            maxval = root->val ; 
        }
        
        solve(root->left, maxval) ; 
        solve(root->right, maxval) ; 
    }
    
    int goodNodes(TreeNode* root) {
       if(root == NULL)
           return 0 ; 
        
        solve(root , INT_MIN) ; 
        return count ; 
    }
};