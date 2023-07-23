class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0  , left = 0 , right = height.size() - 1 ; 
        
        while(left <= right)
        {
            if(height[left] > height[right])
            {
                maxi = max(maxi , height[right] * (right - left)) ; 
                right -- ; 
            }
            else
            {
                maxi = max(maxi , height[left] * (right - left)) ; 
                left++ ; 
            }
            
        }
        return maxi ; 
        
    }
};