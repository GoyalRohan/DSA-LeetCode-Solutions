//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            int n = txt.size() ; 
            int m = pat.size() ; 
            vector <int>  ans ; 
            
            int i=0 , j = 0 ; 
            while(i <= n-m)
            {
                int newi = i ; 
                int j=0 ; 
                while(newi<n && j<m && txt[newi] == pat[j])
                {
                    newi++ ; j++ ; 
                }
                
                if(j==m)
                    ans.push_back(i+1); 

                i++ ; 
            }
            
            if(ans.size() > 0)
                return ans ; 
                
            ans.push_back(-1) ; 
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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends