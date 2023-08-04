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
    int kthele ; 
    
    void solve(TreeNode *root, int k, int &count)
    {
        if(root == NULL)
            return ; 
        solve(root->left , k , count) ; 
        
        count++ ; 
        if(count == k)
        {
            kthele = root->val ; 
            return ; 
        }
        
        solve(root->right, k , count) ; 
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 0 ; 
        solve(root , k , count) ; 
        return kthele ; 
    }
};