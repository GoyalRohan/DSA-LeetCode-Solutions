//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    int solve(int ind, int k, int n , vector<int> &nums, vector<int> &dp)
    {
        if(ind >= n)
            return 0 ; 
            
        if(dp[ind] != -1)
            return dp[ind] ; 
            
        int sum = 0 , words=0 , mincost = INT_MAX ; 
        
        for(int i=ind ; i<n ; i++)
        {
            words++ ; 
            sum = sum + nums[i] ; 
            if(words > 1)
                sum += 1 ; 
                
            if(sum > k)
                break ; 
            
            int space = k - sum ; 
            if(i == n-1)
                space = 0 ; 
                
            int cost = space*space + solve(i+1 , k , n , nums, dp) ; 
            mincost = min(cost , mincost) ; 
        }
        
        return dp[ind] = mincost ; 
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size() ; 
        vector<int> dp(n+1 , -1) ; 
        return solve(0 , k , n , nums , dp) ; 
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends