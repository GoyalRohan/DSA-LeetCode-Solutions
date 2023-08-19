class Dsu {
    private: int n;
    private: vector<int> par, size;

    public: Dsu (int n) {
        this->n = n + 1;
        par.resize(n + 1);
        size.resize(n + 1);
        build(n);
    }

    private: void build (int n) {
        for(int i = 0; i <= n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    public: int find (int node) {
        return node == par[node] ? node : par[node] = find(par[node]);
    }

    public: void unite (int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(size[u] < size[v]) swap(u, v);
        par[v] = u;
        size[u] += size[v];
    }

    public: int findSets(int lo, int hi) {
        int cnt = 0;
        for(int i = lo; i <= hi; i++) {
            cnt += (i == find(i));
        }
        return cnt;
    }

};

class Solution {

private: 
    int findMst (int take, int ignore, int n, int m, vector<vector<int>> &edges) {

        int cost = 0;
        Dsu ds(n);

        if(take != -1) {
            int u = edges[take][0], v = edges[take][1], w = edges[take][2];
            ds.unite(u, v);
            cost += w;
        }

        for(int i = 0; i < m; i++) {
            if(i == ignore) continue;
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if(ds.find(u) == ds.find(v)) continue;
            ds.unite(u, v);
            cost += w;
        }

        return ds.findSets(0, n - 1) == 1 ? cost : 1e9;

    }

public: 
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        int m = edges.size();
        vector<vector<int>> ans(2);

        for(int i = 0; i < m; i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [] (vector<int> &left, vector<int> &right) {
            return left[2] < right[2];
        });

        int expected = findMst(-1, -1, n, m, edges);

        for(int i = 0; i < m; i++) {
            int idx = edges[i][3];
            int with = findMst(i, -1, n, m, edges);
            int without = findMst(-1, i, n, m, edges);
            
            if(without > expected) {
                ans[0].push_back(idx);
            } else if(with == expected) {
                ans[1].push_back(idx);
            }
        }
        
        return ans;

    }
};