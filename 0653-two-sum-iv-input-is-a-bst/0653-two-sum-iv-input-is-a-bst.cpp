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
    
    class bstIterator {
        public : 
            bool reverse ; 
            stack<TreeNode*> st ; 
        
            bstIterator(TreeNode *root, bool isReverse)
            {
                reverse = isReverse ; 
                pushAll(root) ; 
            }
            
            void pushAll(TreeNode *root)
            {
                while(root)
                {
                    st.push(root) ; 
                    if(reverse)
                        root = root->right ; 
                    else
                        root = root->left ; 
                }
            }
        
            int next()
            {
                TreeNode *topnode = st.top() ; 
                st.pop() ; 
                if(reverse)
                    pushAll(topnode->left) ; 
                else
                    pushAll(topnode->right) ; 
                
                return topnode->val ; 
            }
    };
    
    bool findTarget(TreeNode* root, int k) {
        bstIterator l(root , false ) ; 
        bstIterator r(root , true ) ; 
        
        int i = l.next() , j = r.next() ; 
        while(i < j)
        {
            if(i + j == k)
                return true ; 
            else if(i+j < k)
                i = l.next() ; 
            else
                j = r.next() ; 
        }
        
        return false ; 
    }
};