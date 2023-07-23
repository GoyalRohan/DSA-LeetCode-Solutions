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
    
    int findDia(TreeNode *root , int &maxi)
    {
        if(root == NULL)
            return 0 ; 
        
        int lf = findDia(root->left , maxi)  ;
        int rf = findDia(root->right , maxi) ;
        
        maxi = max(maxi , lf + rf) ; 
        
        return 1 + max(lf , rf) ;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0 ;
        
        findDia(root , maxi) ; 
        
        return maxi ; 
    }
};