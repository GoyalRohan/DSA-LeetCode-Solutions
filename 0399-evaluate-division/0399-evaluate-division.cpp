class Solution {
public:
    
    double dfs(string s , string &d , unordered_map<string, unordered_map<string, double>> &adj , unordered_set<string> &vis)
    {
        if(adj[s].find(d) != adj[s].end())
        {
            return adj[s][d] ; 
        }
        
        for(auto node : adj[s])
        {
            if(vis.find(node.first) == vis.end())
            {
                vis.insert(node.first) ; 
                double val = dfs(node.first , d , adj , vis) ; 
                if(val)
                {
                    adj[s][d] = node.second * val ; 
                    return adj[s][d] ; 
                }
            }
        }
        
        return 0 ; 
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)     {
        vector<double> ans ; 
        unordered_map<string, unordered_map<string, double>> adj ; 
        
        for(int i=0 ; i<equations.size() ; i++)
        {
            adj[equations[i][0]][equations[i][1]] = values[i] ; 
            adj[equations[i][1]][equations[i][0]] = (double)1/values[i] ; 
        }
        
        for(int i=0 ; i<queries.size() ; i++)
        {
            string s = queries[i][0] , d = queries[i][1] ; 
            unordered_set<string> vis ; 
            double val = dfs(s , d , adj , vis) ; 
            if(val)
                ans.push_back(val) ; 
            else
                ans.push_back(-1.0) ; 
        }
        
        return ans ; 
    }
};