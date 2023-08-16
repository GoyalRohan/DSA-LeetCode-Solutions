class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size() ; 
        int totsum = 0 ; 
        for(int i=0 ; i<n ; i++)
            totsum += arr[i] ; 

        if(totsum % 2 != 0)
            return false ; 

        int k= totsum/2 ; 
        vector<vector<bool>> dp(n , vector<bool>(k+1 , false)) ; 

        for(int i=0 ; i<n ; i++)
        {
            dp[i][0]= true ; 
        }

        if(k >= arr[0])
            dp[0][arr[0]] = true ;

        for(int i=1 ; i<n ; i++)
        {
            for(int target = 1 ; target <= k ; target++)
            {
                bool notpick = dp[i-1][target] ; 
                bool pick = false ; 
                if(arr[i] <= target)
                    pick = dp[i-1][target - arr[i]] ; 

                dp[i][target] = pick || notpick ; 
            }
        }

        return dp[n-1][k] ; 
    }
};