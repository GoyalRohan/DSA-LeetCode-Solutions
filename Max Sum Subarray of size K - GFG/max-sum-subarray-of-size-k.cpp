//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &Arr , int N){
        // code here 
        int i = 0 , j = 0 ; 
        long sum = 0 , maxsum = 0 ; 
        
        for(j=0 ; j<k ;j++)
            sum += Arr[j] ; 
            
        maxsum = max(maxsum, sum) ; 
        // cout<<maxsum<<endl ; 
        
        while(j<Arr.size())
        {
            sum += Arr[j] - Arr[i] ; 
           maxsum = max(sum, maxsum) ; 
           i++ ; j++ ; 
        }
        
        return maxsum ; 
            
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends