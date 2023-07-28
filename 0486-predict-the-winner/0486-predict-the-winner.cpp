class Solution {
public:
    
    int solve(int i, int j , vector<int> &nums)
    {
        if(i > j)
            return 0 ; 
        
        if(i==j)
            return nums[i] ; 
        
        int take_i = nums[i] + min(solve(i+2 , j , nums) , solve(i+1 , j-1, nums)) ; 
        int take_j = nums[j] + min(solve(i+1 , j-1 , nums) , solve(i , j-2 ,nums)) ; 
        
        return max(take_i , take_j) ; 
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int score = 0 ; 
        for(auto n : nums)
            score += n ;
        
        int n = nums.size() ; 
        int play1= solve(0 , n-1 , nums) ; 
        int play2 = score - play1 ; 
        
        return play1 >= play2 ; 
    }
};