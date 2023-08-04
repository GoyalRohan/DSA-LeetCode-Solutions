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
    
    TreeNode *findLast(TreeNode *root)
    {
        while(root->right)
            root = root->right ; 
        
        return root ; 
    }
    
    TreeNode *helper(TreeNode *root)
    {
        if(!root->left)
            return root->right ; 
        if(!root->right)
            return root->left ;
        
        TreeNode *rightChild = root->right ; 
        TreeNode *lastRight = findLast(root->left) ; 
        lastRight->right = rightChild ; 
        
        return root->left ; 
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL ; 
        
        if(root->val == key)
            return helper(root) ;
        
        TreeNode *cur = root ; 
        while(cur)
        {
            if(key < cur->val)
            {
                if(cur->left && cur->left->val == key)
                {
                    cur->left = helper(cur->left) ; 
                    return root ; 
                }
                else
                    cur = cur->left ; 
            }
            else
            {
                if(cur->right && cur->right->val == key)
                {
                    cur->right = helper(cur->right) ; 
                    return root ; 
                }
                else
                    cur = cur->right ; 
            }
        }
        
        return root ; 
    }
};