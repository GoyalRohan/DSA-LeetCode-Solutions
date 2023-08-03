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
    int sum = 0 ; 
    
    bool isLeaf(TreeNode *root)
    {
        if(!root->left && !root->right)
            return true ; 
        return false ; 
    }
    
    void findSum(TreeNode *root , bool isLeft)
    {
        if(!root)
            return ; 
        if(isLeaf(root) && isLeft)
        {
            sum += root->val ; 
            return ; 
        }
        
        findSum(root->left , true); 
        findSum(root->right ,false) ; 
    }
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        findSum(root , false) ; 
        return sum ; 
    }
};