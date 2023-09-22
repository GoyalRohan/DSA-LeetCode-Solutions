class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size() ; 
        vector<int> dp1(n , 1) , count(n, 1) ; 
        int maxi = 1 ; 
        
        for(int ind=1 ; ind<n ; ind++)
        {
            for(int prev=0 ; prev<ind ; prev++)
            {
                if(arr[ind] > arr[prev] && dp1[ind] < 1 + dp1[prev])
                {
                    dp1[ind] = 1 + dp1[prev] ; 
                    count[ind] = count[prev]; 
                }
                else if(arr[ind] > arr[prev] && dp1[ind] == 1 + dp1[prev])
                    count[ind] += count[prev] ; 
                
            }
            
            maxi = max(maxi, dp1[ind]) ; 
        }
        
        int nos = 0 ; 
        for(int i=0 ; i<arr.size() ; i++)
        {
            if(dp1[i] == maxi)
                nos += count[i] ; 
        }
        
        return nos ; 
        
    }
};