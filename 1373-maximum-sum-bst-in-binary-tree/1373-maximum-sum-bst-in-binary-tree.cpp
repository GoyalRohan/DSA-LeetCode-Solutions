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
    
    int maxsum = 0 ; 
    
    class nodeInfo {
        
        public : 
        int maxsize ; 
        int maxnode ; 
        int minnode ; 
        int sum ; 
        
        nodeInfo(int size , int lnode , int rnode , int val)
        {
            maxsize = size ; minnode = lnode ; maxnode = rnode ; sum = val;
        }
    } ; 
    
    nodeInfo *solve(TreeNode* root)
    {
        if(root == NULL)
            return new nodeInfo(0 , INT_MAX , INT_MIN , 0) ; 
            
        auto leftInfo = solve(root->left) ; 
        auto rightInfo = solve(root->right) ; 
        
        if(leftInfo->maxnode < root->val && rightInfo->minnode > root->val )
        {
            
            nodeInfo *temp =  new nodeInfo(1 + leftInfo->maxsize + rightInfo->maxsize , min(root->val , leftInfo->minnode) ,max(root->val , rightInfo->maxnode) , root->val + leftInfo->sum + rightInfo->sum) ; 
            
            maxsum = max(maxsum , temp->sum) ; 
            return temp ; 
        }
            
    
        else
            return new nodeInfo(max(leftInfo->maxsize , rightInfo->maxsize) , INT_MIN , INT_MAX , 0) ;
        
    }
    
    int maxSumBST(TreeNode* root) {
        nodeInfo *temp = solve(root) ; 
        return maxsum; 
    }
};