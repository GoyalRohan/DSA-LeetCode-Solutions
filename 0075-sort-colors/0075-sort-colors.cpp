class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> freq(3,0) ; 
        
        
        for(int i=0 ; i<n ; i++)
        {
            freq[nums[i]]++ ; 
        }
        
        int j = 0 ; 
        for(int i=0 ; i<=2 ; i++)
        {
            while(freq[i] > 0)
            {
                nums[j++] = i ; 
                freq[i]-- ; 
            }
        }
        
    }
};