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
    
    vector<vector<int>> ans ; 
    
    void solve(TreeNode *root , int &sum , int &targetSum , vector<int> &output)
    {
        if(root == NULL)
            return ; 
        
        sum += root->val ; 
        output.push_back(root->val) ; 
        
        if(!root->left && !root->right)
        {  
            if(sum == targetSum)
                ans.push_back(output) ; 
            // return ; 
        }
        
        solve(root->left , sum , targetSum , output) ; 
        solve(root->right , sum , targetSum , output) ; 
        
        sum -= root->val ; 
        output.pop_back() ; 
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> output ;
        int sum = 0 ; 
        solve(root , sum , targetSum , output) ; 
        return ans ;
    } 
};