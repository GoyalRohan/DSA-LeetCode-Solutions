// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int lcs(int i, int j, string s , string t , int count)
    {
        if(i<0 || j<0)
            return count ; 
        
        if(s[i] == t[j])
        {
            count = lcs(i-1 , j-1 , s , t , count+1) ; 
        }
        else
            count = max(count , max(lcs(i-1 , j , s , t, 0) , lcs(i , j-1, s , t , 0))) ; 
            
        return count ; 
    }
    
    int longestCommonSubstr (string s, string t, int n, int m)
    {
        // your code here
        int ans = 0 ; 
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0)) ; 
        
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=m ; j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1] ; 
                    ans = max(ans , dp[i][j]) ; 
                }
                else
                    dp[i][j] = 0 ; 
            }
        }

        return ans ; 

        // return lcs(n-1 , m-1 , s , t , 0) ; 
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends