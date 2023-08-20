class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector <vector <int>> g(m);
        vector <int> id(m, 0);
        vector <vector <int>> x(m);
        vector <int> pos(n);
        for (int i=0; i<n; i++)
        {
            if (group[i]==-1)
            {
                x.push_back({i});
                g.push_back({});
                id.push_back(0);
                group[i] = m++;
            }
            
            else
            {
                pos[i] = x[group[i]].size();
                x[group[i]].push_back(i);
            }
        }
        
        vector <map <int, vector <int>>> gi(m);
        vector <int> iz(n, 0);
        
        for (int i=0; i<n; i++)
        {
            int b = beforeItems[i].size();
            for (int j=0; j<b; j++)
            {
                if (group[i]!=group[beforeItems[i][j]])
                {
                    g[group[beforeItems[i][j]]].push_back(group[i]);
                    id[group[i]]++;
                }
                
                else
                {
                    iz[i]++;
                    gi[group[i]][beforeItems[i][j]].push_back(i);
                }
            }
        }
        
        queue <int> q;        
        for (int i=0; i<m; i++)
            if (!id[i])
                q.push(i);
            
        vector <int> ans;
        while (!q.empty())
        {
            int ix = q.front();
            q.pop();
            
            queue <int> qt;
            for (int i=0; i<x[ix].size(); i++)
            {
                if (!iz[x[ix][i]])
                    qt.push(x[ix][i]);
            }
                
            while (!qt.empty())
            {
                int v = qt.front();
                qt.pop();
                ans.push_back(v);
                for (int j=0; j<gi[ix][v].size(); j++)
                {
                    iz[gi[ix][v][j]]--;
                    if (!iz[gi[ix][v][j]])
                        qt.push(gi[ix][v][j]);
                }
            }   
            
            for (int i=0; i<g[ix].size(); i++)
            {
                id[g[ix][i]]--;
                if (!id[g[ix][i]])
                    q.push(g[ix][i]);
            }
        }
        
        if (ans.size()!=n)
            return {};
        return ans;
    }
};