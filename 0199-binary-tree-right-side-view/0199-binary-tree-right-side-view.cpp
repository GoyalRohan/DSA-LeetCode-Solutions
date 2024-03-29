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
    
    void solve(TreeNode *root , int level , vector<int> &ans)
    {
        if(root == NULL)
            return  ; 
        
        if(ans.size() == level)
            ans.push_back(root->val) ; 
        
        solve(root->right , level+1 , ans) ; 
        solve(root->left , level+1 , ans) ; 
    }
    
    vector<int> rightSideView(TreeNode* root) {
//         map<int , int> mpp ; 
        vector<int> ans ; 
//         queue<pair<TreeNode* , int>> q ; 
        
        if(!root)
            return ans ; 
        
//         q.push({root , 0}) ; 
        
//         while(!q.empty())
//         {
//             auto p = q.front()  ;q.pop() ;
//             TreeNode *node = p.first ; 
//             int level = p.second ; 
            
//             if(mpp.find(level) == mpp.end())
//             {
//                 mpp[level] = node->val ; 
//             }
            
//             if(node->right)
//                 q.push({node->right , level+1}) ; 
//             if(node->left)
//                 q.push({node->left , level+1}) ;
//         }
        
//         for(auto m : mpp)
//         {
//             ans.push_back(m.second) ; 
//         }
        
        solve(root , 0 , ans) ; 
        
        return ans ; 
    }
};