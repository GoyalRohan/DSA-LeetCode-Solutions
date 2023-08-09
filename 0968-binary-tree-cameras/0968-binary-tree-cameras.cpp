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
    
    #define inf 1e9 ; 
    map<pair<TreeNode* , pair<bool, bool>> , int> dp ; 
    
    
    int solve(TreeNode *root , bool cam , bool parentcam)
    {
        if(!root)
        {
            if(cam)
                return inf ; 
            return 0 ; 
        }
        
        if(!root->left && !root->right)
        {
            if(cam)
                return 1 ; 
            else
            {
                if(parentcam)
                    return 0 ; 
                else
                    return inf ; 
            }
        }
        
        if(dp.find({root , {cam, parentcam}}) != dp.end())
            return dp[{root , {cam , parentcam}}] ; 
        
        if(cam)
        {
            int lans = min(solve(root->left , 1 , 1) , solve(root->left , 0 , 1)) ; 
            int rans = min(solve(root->right, 1 , 1) , solve(root->right, 0 , 1)) ; 
            return dp[{root , {cam , parentcam}}] = 1 + lans + rans ; 
        }
        else
        {
            if(parentcam)
            {
                int lans = min(solve(root->left , 1 , 0) , solve(root->left , 0 , 0)) ; 
                int rans = min(solve(root->right, 1 , 0) , solve(root->right, 0 , 0)) ; 
                return dp[{root , {cam , parentcam}}] = lans + rans ; 
            }
            else
            {
                int op1 = solve(root->left, 1, 0) + min(solve(root->right, 0, 0) , solve(root->right, 1 , 0)) ; 
                int op2 = solve(root->right , 1 , 0) + min(solve(root->left, 0, 0) , solve(root->left, 1, 0)) ; 
                
                return dp[{root , {cam , parentcam}}] = min(op1 , op2) ; 
            }
        }
    }
    
    int minCameraCover(TreeNode* root) {
        return min(solve(root , 1 , 0) , solve(root, 0 , 0)) ; 
    }
};