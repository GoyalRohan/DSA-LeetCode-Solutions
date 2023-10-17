class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> h(n+1,0);
        
        for(auto i:nums){
            if(i>=1 && i<=n)
                h[i]++;
            
        }
        
        for(int i = 1 ; i <= n ; i++){
            
            if(h[i] == 0)
                return i;
            
        }
        
        return n+1;
        
        
    }
};