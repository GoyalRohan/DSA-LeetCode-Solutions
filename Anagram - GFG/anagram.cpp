//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string s, string t){
        
        // Your code here
        unordered_map<char, int> mpp1, mpp2 ; 
        
        for(auto a : s)
            mpp1[a]++ ; 
        
        for(auto a : t)
            mpp2[a]++ ; 
        
        return  mpp1 == mpp2 ; 
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends