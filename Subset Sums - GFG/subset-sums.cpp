//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> ans ; 

    void solve(int ind , vector<int> &arr , int &sum)
    {
        if(ind == arr.size())
        {
            ans.push_back(sum) ; 
            return  ;
        }
        
        solve(ind+1 , arr , sum) ; 
        
        sum += arr[ind] ; 
        solve(ind+1 , arr , sum) ; 
        sum -= arr[ind] ;
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        int sum = 0 ; 
        solve(0 , arr , sum) ; 
        return ans ; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends