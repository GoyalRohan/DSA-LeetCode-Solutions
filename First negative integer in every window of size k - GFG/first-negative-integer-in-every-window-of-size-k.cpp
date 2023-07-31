//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
      
    priority_queue<pair<long long int, long long int> , vector<pair<long long int , long long int>> , greater<pair<long long int, long long int>>> pq ; 
    long long int i = 0 ; 
    
    for(i=0 ; i<k-1 ; i++)
    {
        if(A[i] < 0)
        {
            // cout<<A[i]<<endl ; 
            pq.push({i , A[i]}) ; 
        }
            
    }
    
    vector<long long> ans ; 
    for(i=k-1 ; i<N ; i++)
    {
        if(A[i] < 0)
            pq.push({i , A[i]}) ; 
            
        while(!pq.empty() && pq.top().first < i-k+1)
            pq.pop() ; 
            
        if(!pq.empty())
        {
            ans.push_back(pq.top().second) ; 
        }
        else
            ans.push_back(0) ; 
    }
    
    return ans ; 
 }