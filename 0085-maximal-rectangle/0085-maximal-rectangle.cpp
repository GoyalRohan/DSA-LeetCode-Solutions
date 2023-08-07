class Solution {
public:
    
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        stack<int> st ; 
        st.push(-1) ; 
        vector<int> next(n) ;
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            int cur= arr[i] ; 
            while(st.top() != -1 && arr[st.top()] >= cur)
                st.pop() ; 
            
            next[i] = st.top() ; 
            st.push(i) ; 
        }
        
        return next ; 
    }
    
    vector<int> prevSmallerElement(vector<int> &arr, int n)
    {
        // Write your code here.
        stack<int> st ; 
        st.push(-1) ; 
        vector<int> next(n) ; 

        for(int i=0 ; i<n ; i++)
        {
            int cur = arr[i] ; 
            while(st.top() != -1 && arr[st.top()] >= cur)
                st.pop() ; 

            next[i] = st.top() ; 
            st.push(i) ; 
        }

        return next ; 
    }
    
    int areaHistogram(vector<int> &heights , int m)
    {
        vector<int> next = nextSmallerElement(heights, m) ; 
        vector<int> prev = prevSmallerElement(heights, m) ;
            
        int maxarea = INT_MIN ; 
        for(int i=0 ; i<m ; i++)
        {
            int len = heights[i] ; 
            if(next[i] == -1)
                next[i] = m ;
            
            int width = next[i] - prev[i] - 1 ; 
            int area = len * width ; 
            maxarea = max(area , maxarea) ; 
        }
        
        return maxarea ; 
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ; 
        vector<int> heights(m , 0) ;
        int maxarea = 0 ; 
        
        for(int i=0 ; i<n ;i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(matrix[i][j] == '1')
                    heights[j] += 1 ; 
                else
                    heights[j] = 0;
            }
            
            int area = areaHistogram(heights , m) ; 
            maxarea = max(area , maxarea) ; 
            
        }
        
        return maxarea ; 
    }
};