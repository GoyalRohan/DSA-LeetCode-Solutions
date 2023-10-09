class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1 , last = -1 ; 
        int n = nums.size() ; 
        
        if(nums.size() == 0)
            return {-1, -1} ; 
        
        first = lower_bound(nums.begin(), nums.end() , target ) - nums.begin(); 
        // cout<<first<<" " ; 
        if(first == n)
            first = -1 ; 
        if((first != -1 && first != n) && nums[first] != target)
            first = -1 ; 
        
        last = upper_bound(nums.begin(), nums.end() , target ) - nums.begin() -1; 
        
        if((last != -1 && last != n) && nums[last] != target)
            last = -1 ; 
        
//         if(first == -1 || last == -1)
//             return {first, last} ; 

        
//         if(nums[first] != target)
//             first = -1 ; 
//         cout<<"Fsfs" ; 
//         if(nums[last] != target)
//             last = -1 ; 
        
        
        return {first, last} ; 
    }
};