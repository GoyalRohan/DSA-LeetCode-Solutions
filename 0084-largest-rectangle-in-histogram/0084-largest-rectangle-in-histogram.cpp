class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ; 
        vector<int> nextSmaller(n, 0) ; 
        vector<int> prevSmaller(n , 0) ; 
        
        stack<int> st ;
        st.push(-1) ; 
        
        for(int i=n-1; i>=0 ; i--)
        {
            int cur = heights[i] ; 
            while(st.top() != -1 && heights[st.top()] >= cur)
                st.pop() ; 
            
            nextSmaller[i] = st.top() ; 
            st.push(i) ; 
        }
        
        stack<int> st1 ;
        st1.push(-1) ; 
        
        for(int i=0; i<n ; i++)
        {
            int cur = heights[i] ; 
            while(st1.top() != -1 && heights[st1.top()] >= cur)
                st1.pop() ; 
            
            prevSmaller[i] = st1.top() ; 
            st1.push(i) ; 
        }
        
        
        int maxArea = 0 ; 
        
        for(int i=0 ; i<n ; i++)
        {
            if(nextSmaller[i] == -1)
                nextSmaller[i] = n ; 
            
            int area = heights[i] * (nextSmaller[i] - prevSmaller[i]-1) ;  
            maxArea = max(area , maxArea) ; 
        }
        
        return maxArea ; 
 
        
    }
};