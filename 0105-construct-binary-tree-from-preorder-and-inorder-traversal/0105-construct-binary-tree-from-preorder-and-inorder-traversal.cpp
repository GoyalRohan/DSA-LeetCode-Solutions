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
    
    TreeNode *build(int prestart, int preend, int instart, int inend, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &inmap)
    {
        if(prestart > preend || instart > inend)
            return NULL ; 
        
        TreeNode *root = new TreeNode(preorder[prestart]) ; 
        int inroot = inmap[preorder[prestart]] ; 
        int numsleft = inroot - instart ; 
        
        root->left = build(prestart+1 , prestart+numsleft, instart , inroot-1 , preorder, inorder, inmap) ; 
        root->right = build(prestart+numsleft+1 , preend, inroot+1 , inend , preorder, inorder, inmap) ; 
        
        return root ; 
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inmap ; 
        for(int i=0 ; i<inorder.size() ; i++)
            inmap[inorder[i]] = i ; 
        
        return build(0 , preorder.size()-1 , 0 , inorder.size()-1 , preorder, inorder, inmap) ; 
    }
};