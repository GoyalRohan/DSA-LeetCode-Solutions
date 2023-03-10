class Solution {
public:
    int merge(vector<int> &nums , int low , int mid , int high)
    {
        int cnt = 0 ; 
        int j = mid+1 ; 
        
        for(int i =low ; i<=mid ; i++)
        {
            while(j <= high && (long)nums[i] > (long)2*nums[j])
                j++ ; 
            
            cnt += j - (mid+1) ; 
        }
        
        vector<int> temp; 
        int i = low ;  j = mid+1 ; 
        
        while(i<=mid && j<= high )
        {
            if(nums[i] <= nums[j])
                temp.push_back(nums[i++]) ; 
            else
                temp.push_back(nums[j++]) ; 
        }
        
        while(i <= mid)
            temp.push_back(nums[i++]) ; 
        
        while(j <= high)
            temp.push_back(nums[j++]) ; 
        
        for(int i=low ; i<=high ; i++)
        {
            nums[i] = temp[i - low] ; 
        }
        
        return cnt ; 
        
    }
    
    
    int mergeSort(vector<int>& nums , int low , int high)
    {
        if(low >= high)
            return  0; 
        
        int inv = 0 ;
        int mid = (low + high)/2 ; 
        inv += mergeSort(nums, low , mid) ; 
        inv += mergeSort(nums , mid+1 , high) ; 
        inv += merge(nums , low , mid , high) ; 
        
        return inv ; 
        
        
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums ,0 ,nums.size() - 1) ; 
    }
};