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
    
    void pre(TreeNode *root , string &ans)
    {
        if(root == NULL)
            return ; 
        
        if(!root->left && !root->right)
            ans += to_string(root->val) + "#"  ;
        
        pre(root->left , ans) ; 
        pre(root->right , ans) ; 
        
        
    }
        
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string ans1 = "" , ans2 = "" ; 
        pre(root1 , ans1) ; 
        pre(root2 , ans2) ; 
        
        return ans1 == ans2 ; 
    }
};