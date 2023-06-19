//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int cutRod(int price[], int N) {
        //code here
        // vector<vector<int>> dp(n , vector<int>(n+1 , -1)) ;  
        vector<int> dp(N+1 , 0) ; 
        
        for(int n=1 ; n<=N ; n++)
        {
            int maxi = 0 ;   
            for(int i=1 ; i<=n ; i++)
            {
                int cost = price[i-1] + dp[n-i] ; 
                maxi = max(maxi, cost) ; 
            }
            
            dp[n] =  maxi ; 
        }
        
        return dp[N] ; 
        // return solve( n , price , dp) ; 
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