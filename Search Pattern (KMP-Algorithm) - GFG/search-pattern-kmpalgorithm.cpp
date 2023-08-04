//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<int> fillLps(string pat , int m)
    {
        vector<int> lps(m , 0) ;
        int len = 0 ; 
        
        for(int i=1 ; i<m ; i++)
        {
            if(pat[i] == pat[len])
            {
                len++ ; 
                lps[i] = len ; 
            }
            else
            {
                if(len == 0)
                    lps[i] = 0 ; 
                else
                    len = lps[len-1] ; 
            }
        }
        
        return lps ; 
        
    }
    
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            int n = txt.size() ; 
            int m = pat.size() ; 
            vector <int>  ans ; 
            
            vector<int> lps = fillLps(pat , m) ; 
            
            int i=0 , j= 0 ;
            while(i<n)
            {
                if(txt[i] == pat[j]) 
                {
                    i++ ; j++ ; 
                    if(j == m)
                    {
                        ans.push_back(i-m+1) ; 
                        j = lps[j-1] ; 
                    }
                }
                else
                {
                    if(j == 0)
                        i++ ; 
                    else
                        j = lps[j-1] ; 
                }
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