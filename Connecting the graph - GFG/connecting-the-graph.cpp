//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int i, vector<int> &vis , vector<int> adj[])
    {
        vis[i] = 1 ; 
        for(auto it : adj[i])
        {
            if(vis[it] == 0)
                dfs(it , vis , adj) ; 
        }
    }
  
    int Solve(int n, vector<vector<int>>& connections) {
        // code here
        vector<int> adj[n] ; 
        int edges = 0 ; 
        
        for(int i=0 ; i<connections.size() ; i++)
        {
            int u= connections[i][0] ; 
            int v= connections[i][1] ; 
            
            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
            edges++ ; 
        }
        
        if(edges < n-1)
            return -1 ; 
        
        int components  = 0 ; 
        vector<int> vis(n, 0) ; 
        
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i] == 0)
            {
                components++ ;
                dfs(i , vis, adj) ; 
            }
        }

        int red = edges - ((n-1) - (components-1)) ; 
        if(red >= (components - 1))
            return components - 1 ; 
        
        return -1 ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends