class Solution {
public:
    
    void merge(vector<pair<int,int>> &nums , int low , int mid , int high , vector<int> &count)
    {
        vector<pair<int,int>> temp(high - low +1) ; 
        int i=low , j = mid+1 , k=0 ; 
        
        while(i<=mid && j<=high)
        {
            if(nums[i].first <= nums[j].first)
            {
                temp[k++] = nums[j++] ; 
            }
            else
            {
                count[nums[i].second] += high - j + 1 ; 
                temp[k++] = nums[i++] ; 
            }
        }
        
        while(i<=mid)
        {
            temp[k++] = nums[i++] ; 
        }
        
        while(j<=high)
        {
            temp[k++] = nums[j++] ; 
        }
        
        for(int i=low ; i<=high ; i++)
            nums[i] = temp[i-low] ; 
    }
    
    void mergeSort(vector<pair<int,int>> &nums, int low, int high, vector<int> &count)
    {
        if(low >= high)
            return ; 
        
        int mid = (low + high)/2 ;
        mergeSort(nums , low , mid , count) ; 
        mergeSort(nums, mid+1 , high , count) ; 
        merge(nums , low , mid , high , count) ; 
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> count(n , 0) ; 
        
        vector<pair<int,int>> arr ; 
        for(int i=0 ; i<n ; i++)
            arr.push_back({nums[i] , i}) ; 
        
        mergeSort(arr , 0 , n-1 , count)  ;
        
        return count ; 
    }
};