class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ; 
        if(n <=2)
            return 0 ; 
        
        int maxleft= height[0] , maxright = height[n-1] ; 
        int left = 1 , right = n-2 ; 
        int ans = 0 ; 
        
        while(left <= right)
        {
            if(maxleft <= maxright)
            {
                if(maxleft > height[left])
                    ans += maxleft - height[left] ; 
                else
                    maxleft = height[left] ; 
                left++ ; 
            }
            else
            {
                if(maxright > height[right])
                    ans += maxright - height[right] ; 
                else
                    maxright = height[right] ; 
                right-- ; 
            }
        }
        
        return ans ; 
    }
};