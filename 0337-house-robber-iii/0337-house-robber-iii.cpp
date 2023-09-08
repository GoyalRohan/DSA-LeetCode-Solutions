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
    
    map<pair<TreeNode* , int> , int> mpp ; 
    
    bool isLeaf(TreeNode *root)
    {
        if(!root->left && !root->right)
            return true ; 
        return false ; 
    }
    
    int solve(TreeNode *root, int take)
    {
        if(root == NULL)
            return 0 ; 
        
        if(isLeaf(root))
        {
            if(take)
                return root->val ; 
            else
                return 0 ; 
        }
        
        if(mpp.find({root , take}) != mpp.end())
            return mpp[{root , take}] ; 
        
        int maxi =  INT_MIN , ans1 = 0 , ans2 = 0 ; 
        if(take)
        {
            ans1 = root->val + solve(root->left, 0) + solve(root->right , 0) ; 
        }
        
        ans2 = 0 + solve(root->left , 1) + solve(root->right , 1) ; 
        
        maxi = max(ans1 , ans2) ; 
        return mpp[{root , take}] = maxi ; 
    }
    
    int rob(TreeNode* root) {
        if(!root)
            return 0 ; 
        
        return max(solve(root , 1) , solve(root, 0)) ; 
    }
};