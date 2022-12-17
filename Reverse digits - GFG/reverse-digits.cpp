//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    long long int helper(long long int n , long long int digits)
	    {
	        
	        if(n%10 == n)
	            return n ; 
	        
	        long long int rem = n % 10 ; 
	        return rem * pow(10 , digits-1)+ helper(n/10 , digits - 1) ; 
	    }
	
		long long int reverse_digit(long long int n)
		{
		    // Code here
            bool isNeg = false ; 
            if(n < 0)
            {
                isNeg = true ; 
                n = -n ; 
             }
                
            
            long long int digits = int(log10(n)) + 1 ; 
            long long int ans = helper(n , digits) ;
            
            if(isNeg == true)
                ans = -ans ; 
                
            return ans ; 
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.reverse_digit(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends