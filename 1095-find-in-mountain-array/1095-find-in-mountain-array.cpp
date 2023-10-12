/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int findPeak(MountainArray &m)
    {
        int start = 0 ; 
        int end = m.length()-1 ; 
        
        while(start < end)
        {
            int mid = start + (end-start)/2 ; 
            if(m.get(mid) < m.get(mid+1)) 
                start = mid+1 ; 
            else
                end = mid ; 
        }
        
        
        return start ; 
    }
    
    int Bsearch(int start , int end , MountainArray &m , int target)
    {
        bool isAsc = m.get(start) < m.get(end) ; 
        
        while(start <= end)
        {
            int mid = start + (end-start)/2 ; 
            
            if(m.get(mid) == target)
                return mid; 
            
            if(isAsc)
            {
                if(m.get(mid) < target)
                    start = mid+1 ; 
                else
                    end = mid - 1 ; 
            }
            else
            {
                if(m.get(mid) > target)
                    start = mid+1 ; 
                else
                    end = mid - 1 ; 
            }
        }
        return -1 ; 
    }
    
    int findInMountainArray(int target, MountainArray &m) {
        int peak = findPeak(m) ; 
        if(m.get(peak) == target ) 
            return peak ; 
        
        
        if(m.get(peak) < target)
            return -1 ; 
        
        int firstTry = Bsearch(0 , peak-1 , m , target) ; 
        if(firstTry != -1)
            return firstTry ; 
        
        return Bsearch(peak+1 , m.length()-1 , m , target) ; 
    }
};