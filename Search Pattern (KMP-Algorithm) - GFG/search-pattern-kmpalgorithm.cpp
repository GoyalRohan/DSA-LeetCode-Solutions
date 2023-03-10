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
            int m = pat.size() ; 
            int n = txt.size() ; 
            vector<int> lps(m , 0) ; 
            
            for(int i=1 ; i<m ; i++)
            {
                int j = lps[i-1] ;
                
                while(j>0 && pat[i] != pat[j])
                    j = lps[j-1] ; 
                    
                if(pat[i] == pat[j])
                    j++ ;
                    
                lps[i] = j ; 
                
            }
            
            vector<int> ans ; 
            int i=0 , j = 0 ; 
            
            while(i<n)
            {
                if(txt[i] == pat[j])
                {
                    i++ ; j++ ; 
                }
                
                if(j == m)
                {
                    ans.push_back(i - (m-1)) ; 
                    j = lps[j-1] ; 
                }
                else if(txt[i] != pat[j])
                {
                    if(j ==0)
                        i++ ; 
                    j = lps[j-1] ; 
                }
                    
            }
            
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