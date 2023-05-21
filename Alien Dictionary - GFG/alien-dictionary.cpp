//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    
    void dfs(int node , vector<int> &vis , vector<vector<int>> &g , string &ans)
    {
        vis[node] = 1 ; 
        for(auto it : g[node])
        {
            if(vis[it] == 0)
                dfs(it , vis , g , ans) ; 
        }
        
        char ch = node + 'a' ; 
        ans = ch + ans ; 
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> g(K) ; 
        
        for(int i=0 ; i<N-1 ; i++)
        {
            string word1 = dict[i] , word2 = dict[i+1] ; 
            for(int j=0 ; j < min(word1.size() , word2.size()) ; j++)
            {
                if(word1[j] != word2[j])
                {
                    g[word1[j] - 'a'].push_back(word2[j] - 'a') ; 
                    break ; 
                }
            }
        }
        
        vector<int> vis(K , 0) ; 
        string ans = "" ; 
        
        for(int i=0 ; i<K ; i++)
        {
            if(!vis[i])
                dfs(i , vis , g , ans) ; 
        }
        
        
        return ans ; 
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends