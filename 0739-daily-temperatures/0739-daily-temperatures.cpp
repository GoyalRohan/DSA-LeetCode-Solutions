class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int> ans ; 
        stack<int> st ;
        int n = arr.size() ; 
        
        st.push(n-1) ; 
        ans.push_back(0) ; 
        
        for(int i=n-2 ; i>=0 ; i--)
        {
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop() ; 
            
            if(st.empty())
                ans.push_back(0) ; 
            else
                ans.push_back(st.top() - i) ; 
            
            st.push(i) ; 
        }
        
        reverse(ans.begin() , ans.end()) ; 
        return ans ; 
    }
};