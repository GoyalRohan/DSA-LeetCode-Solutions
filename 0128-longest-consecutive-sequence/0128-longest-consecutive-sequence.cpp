class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0 ; 
        
        set<int> s ; 
        for(auto nu : nums)
            s.insert(nu) ; 
        
        // sort(nums.begin() , nums.end()) ; 
        
        vector<int> temp ; 
        for(auto st : s)
            temp.push_back(st) ; 
        
        int n = temp.size() ; 
        int cnt = 1 , maxlen = 1 ; 
        
        for(int i=0 ; i<n-1 ; i++)
        {
            if(temp[i] + 1 == temp[i+1])
            {
                cnt++ ; 
                maxlen = max(maxlen , cnt) ; 
            }
            else
                cnt = 1 ; 
        }
        
        return maxlen ; 
    }
};