//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    
    int solve(int length, int x, int y, int z, vector<int> &dp)
    {
        //Your code here
        if(length == 0)
            return 0 ; 
            
        if(dp[length] != -1)
            return dp[length] ; 
        
        int way1 = -1e8 , way2 = -1e8 , way3 = -1e8 ; 
        
        if(length >= x)
            way1 = 1 + solve(length-x , x , y , z, dp) ; 
        if(length >= y)
            way2 = 1 + solve(length-y , x , y , z, dp) ; 
        if(length >= z)
            way3 = 1 + solve(length-z , x , y , z, dp) ; 
            
        return dp[length] = max(way1 , max(way2 , way3)) ; 
    }
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1 , -1) ; 
        int ans = solve(n , x , y , z , dp) ; 
        if(ans < 0)
            return 0 ; 
            
        return ans ; 
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends