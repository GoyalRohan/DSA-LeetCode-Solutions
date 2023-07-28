/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void findParent (TreeNode *root , unordered_map<TreeNode* , TreeNode*> &parentMap)
    {
        queue<TreeNode*> q ; 
        q.push(root) ; 
        
        while(!q.empty())
        {
            auto node = q.front() ; 
            q.pop() ; 
            
            if(node->left)
            {
                q.push(node->left) ; 
                parentMap[node->left] = node ; 
            }
            if(node->right)
            {
                q.push(node->right) ; 
                parentMap[node->right] = node ; 
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans ; 
        unordered_map<TreeNode* , TreeNode*> parentMap ; 
        unordered_map<TreeNode* , bool> vis ; 
        
        findParent(root , parentMap) ; 
        
        queue<TreeNode*> q ; 
        q.push(target) ; 
        vis[target] = true ; 
        
        int curLevel = 0 ; 
        while(!q.empty())
        {
            int size= q.size() ; 
            if(curLevel++ == k)
                break ; 
            
            for(int i=0 ; i<size ; i++)
            {
                auto node = q.front() ; 
                q.pop() ; 
                
                if(node->left && !vis[node->left])
                {
                    q.push(node->left) ;
                    vis[node->left] = true ; 
                }
                
                if(node->right && !vis[node->right])
                {
                    q.push(node->right) ;
                    vis[node->right] = true ; 
                }
                
                if(parentMap[node] && !vis[parentMap[node]])
                {
                    q.push(parentMap[node]) ;
                    vis[parentMap[node]] = true ; 
                }
            }
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val) ; 
            q.pop() ; 
        }
        
        return ans ; 
    }
};