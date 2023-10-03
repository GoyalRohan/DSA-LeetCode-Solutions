class Solution {
public:
    
    int solve(int left ,int right , vector<int>& arr , map<pair<int, int> , int> &maxi, vector<vector<int>> &dp) 
    {
        if(left == right)
            return 0 ; 
        
        if(dp[left][right] != -1)
            return dp[left][right] ; 
        
        int ans = INT_MAX ; 
        for(int i=left ; i<right ; i++)
        {
            ans = min(ans , maxi[{left , i}] * maxi[{i+1,right}] + solve(left,i,arr, maxi, dp) + solve(i+1, right, arr, maxi, dp)) ; 
        }
        
        return dp[left][right] = ans ;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size() ; 
        map<pair<int, int> , int> maxi ; 
        for(int i=0 ; i<n ; i++)
        {
            maxi[{i, i}] = arr[i] ; 
            for(int j=i+1 ; j<n ; j++)
            {
                maxi[{i,j}] = max(arr[j] , maxi[{i , j-1}]) ; 
            }
        }
        
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1)) ; 
        return solve(0 , n-1 , arr , maxi , dp) ; 
    }
};