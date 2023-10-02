class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size() ; 
        vector<int> maxi(n , -1) ;
        stack<int> st ; 
        st.push(nums2[n-1]) ; 
        
        for(int i=n-2; i>=0 ; i--)
        {
            while(!st.empty() && st.top() <= nums2[i])
                st.pop() ; 
            
            if(!st.empty())
                maxi[i] = st.top() ; 
            
            st.push(nums2[i]) ; 
        }
        
        unordered_map<int , int> mpp ; 
        for(int i=0 ; i<n ; i++)
        {
            mpp[nums2[i]] = i ; 
        }
        
        vector<int> res ; 
        for(int i=0 ; i<nums1.size() ; i++)
        {
            int ind = mpp[nums1[i]] ; 
            res.push_back(maxi[ind]) ; 
        }
        
        return res ; 
    }
};