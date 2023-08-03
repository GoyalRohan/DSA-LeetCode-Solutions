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
    bool first = 0 ; 
    
    bool check(TreeNode *root ,int sum, int targetSum)
    {
        if(!root)
            return false ; 
        
        if(!root->left && !root->right)
        {
            sum += root->val ; 
            if(sum == targetSum)
                return true ; 
            
            return false ; 
        }
        
        sum += root->val ; 
        bool lans = check(root->left , sum , targetSum) ; 
        bool rans = check(root->right , sum , targetSum) ; 
        sum -= root->val ; 
        
        if(lans || rans)
            return true ; 
        
        return false ; 
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL)
            return false ; 
        
        return check(root , 0 ,targetSum) ; 
    }
};