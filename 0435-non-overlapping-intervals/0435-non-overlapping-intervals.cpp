class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end()) ; 
        
        int left = 0 , right = 1 , n = intervals.size() , count= 0 ; 
        
        while(right < n)
        {
            if(intervals[left][1] <= intervals[right][0])
            {
                left = right ; 
                right++ ; 
            }
            else if(intervals[left][1] <= intervals[right][1])
            {
                right++ ; 
                count++ ; 
            }
            else if(intervals[left][1] > intervals[right][1])
            {
                left = right ; 
                right++ ; 
                count++ ; 
            }
        }
        
        return count ; 
    }
};