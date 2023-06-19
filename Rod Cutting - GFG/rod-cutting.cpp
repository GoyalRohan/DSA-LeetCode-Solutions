//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int solve(int n , int price[] , vector<int> &dp)
    {
        if(n <= 0)
            return 0 ; 
            
        if(dp[n] != -1)
            return dp[n] ; 
          
        int maxi = 0 ;   
        for(int i=1 ; i<=n ; i++)
        {
            int cost = price[i-1] + solve(n-i , price , dp) ; 
            maxi = max(maxi, cost) ; 
        }
        
        return dp[n] =  maxi ; 
    }
  
    int cutRod(int price[], int n) {
        //code here
        // vector<vector<int>> dp(n , vector<int>(n+1 , -1)) ;  
        vector<int> dp(n+1 , -1) ; 
        return solve( n , price , dp) ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends