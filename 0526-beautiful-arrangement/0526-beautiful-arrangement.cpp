class Solution {
public:
    
    int ans = 0 ; 
    
    void solve(int ind, int n, vector<int> &nums)
    {
        if(ind == n+1)
        {
            ans++ ; 
            return ; 
        }
        
        for(int i=ind; i<=n ; i++)
        {
            swap(nums[i], nums[ind]) ; 
            if((nums[ind]%ind == 0) || (ind%nums[ind]==0))
                solve(ind+1 , n , nums) ; 
            swap(nums[i], nums[ind]) ; 

        }
    }
    
    int countArrangement(int n) {
        vector<int> nums(n+1 , 0) ;
        for(int i=1 ; i<=n ; i++)
        {
            nums[i] = i ;     
        }
        // cout<<"sfdsfs" ; 
        solve(1 , n, nums) ; 
        return ans ;
    }
};