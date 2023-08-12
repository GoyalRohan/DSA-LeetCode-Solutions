class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums ; 
        sort(temp.begin(), temp.end()) ; 
        
        int n = nums.size() ; 
        
        int i=0 , j = n-1 ; 
        
        for(i=0 ; i<n ; i++)
        {
            if(temp[i] != nums[i])
                break ; 
        }
        if(i==n)
            return 0 ; 
        
        for(j=n-1 ; j>=0 ; j--)
        {
            if(temp[j] != nums[j])
                break ; 
        }
        
        return j-i+1 ; 
    }
};