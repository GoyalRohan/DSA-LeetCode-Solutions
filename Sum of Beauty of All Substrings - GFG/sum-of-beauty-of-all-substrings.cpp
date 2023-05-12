//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int n = s.size() , sum = 0; 
        
        for(int i=0 ; i<n-1 ; i++)
        {
            vector<int> count(26, 0) ; 
            
            for(int j=i ; j<n ; j++)
            {
                count[s[j]- 'a']++ ; 
                
                int mini = INT_MAX , maxi = INT_MIN ;
                for(int i=0 ; i<26 ; i++)
                {
                    if(count[i] != 0)
                    {
                        maxi = max(maxi, count[i]) ; 
                        mini = min(mini, count[i]) ; 
                    }
                }
                
                sum += maxi - mini ; 
            }
        }
        
        return sum ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends