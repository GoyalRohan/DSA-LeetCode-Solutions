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
    
//     void invert(TreeNode* leftnode , TreeNode* rightnode)
//     {
//         if(!leftnode && !rightnode)
//             return NULL ; 
        
//         if(!leftnode)
//             return rightnode ; 
//         if(!rightnode)
//             return leftnode ; 
        
        
//     }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL ; 
        
        root->left = invertTree(root->left) ; 
        root->right = invertTree(root->right) ; 
        
        swap(root->left , root->right) ; 
        
        return root ; 
    }
};