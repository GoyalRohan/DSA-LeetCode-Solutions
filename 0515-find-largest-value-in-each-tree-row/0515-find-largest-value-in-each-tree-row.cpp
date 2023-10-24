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
    
    map<int, int> mpp ; 
    vector<int> ans ; 
    
    void preorder(TreeNode *root, int level)
    {
        if(root == NULL)
            return ; 
        
        if(mpp.find(level) == mpp.end())
            mpp[level] = root->val ; 
        else
            mpp[level] = max(mpp[level] , root->val) ; 
        
        preorder(root->left , level+1) ; 
        preorder(root->right, level+1) ; 
    }
    
    vector<int> largestValues(TreeNode* root) {
        
        if(root == NULL)
            return ans ; 
        
        preorder(root, 0) ; 
        for(auto m : mpp)
            ans.push_back(m.second) ; 
        
        return ans ; 
    }
};