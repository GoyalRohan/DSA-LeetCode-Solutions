class Solution {
public:
    
    void topoSort(int node, int n , vector<int> &vis , vector<int> adj[] , stack<int> &st)
    {
        vis[node] = 1 ; 
        for(auto it : adj[node])
        {
            if(vis[it] == 0)
                topoSort(it, n , vis ,  adj ,st) ; 
        }
        
        // cout<<node<<endl; 
        st.push(node) ; 
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> result ; 
        vector<int> vis(n , 0) ; 
        vector<int> adj[n] ; 
        stack<int> st ; 
        
        for(int i=0 ; i<edges.size() ; i++)
        {
            int u = edges[i][0] , v= edges[i][1] ; 
            adj[u].push_back(v) ; 
        }
        
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i] == 0)
                topoSort(i , n, vis , adj ,st) ; 
        }
        
        vector<int> seq ; 
        while(!st.empty())
        {
            cout<<st.top() ; 
            seq.push_back(st.top()) ; 
            st.pop() ; 
        }
        
        for(int i=0 ; i<n ; i++)
        {
            vis[i] = 0 ; 
        }
        
        for(auto s: seq){
            if(vis[s] == 0)
            {
                topoSort(s , n, vis, adj , st) ; 
                result.push_back(s) ; 
            }
                
        }
        
        return result ; 
        
    }
};