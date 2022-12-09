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
    
    void maxAncUtil(TreeNode *root, int &maxi , int value)
    {
        if(root == NULL)
            return ; 
        
        maxi = max(maxi , abs(root->val - value)) ; 
        
        maxAncUtil(root->left , maxi , value) ; 
        maxAncUtil(root->right , maxi , value) ; 
        
    }
    
    void maxAnc(TreeNode *root , int &maxi)
    {
        if(root == NULL)
            return ; 
        
        maxAncUtil(root , maxi , root->val) ; 
        maxAnc(root->left , maxi) ; 
        maxAnc(root->right , maxi) ; 
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxi = INT_MIN ; 
        maxAnc(root , maxi) ; 
        return maxi ; 
    }
};