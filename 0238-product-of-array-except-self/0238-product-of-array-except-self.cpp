class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> right(n , 1) , output(n) ; 
        
        int prod = 1 ; 
        for(int i=n-1 ; i>=0 ; i--)
        {
            right[i] = prod ; 
            prod = prod * nums[i] ; 
        }
        
        
        prod = 1 ; 
        
        for(int i=0 ; i<n ; i++)
        {
            output[i] = prod * right[i] ; 
            prod = prod * nums[i] ; 
        }
        
        return output ; 
    }
};