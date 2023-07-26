class Solution {
public:
    
    bool isPossible(int speed , vector<int>& dist, double hour)
    {
        double time = 0.0 ; 
        int n = dist.size() ; 
        
        for(int i=0 ; i<n ; i++)
        {
            double temp = (double)dist[i]/(double)speed ; 
            if(i == n-1)
            {
                if(time + temp <= hour)
                    return true ; 
                return false ; 
            }
            else
                time += ceil(temp) ; 
        }
        
        return false ; 
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size() ; 
        // if(hour < (double)n-1)
        //     return -1 ; 
        
        int low = 1 , high = 1e9 ,ans = -1; 
        
        while(low <= high)
        {
            int mid = (low + high)/2 ; 
            
            if(isPossible(mid , dist , hour))
            {
                ans = mid ; 
                high = mid-1 ; 
            }
            else
                low = mid+1 ; 
        }
        
        return ans ; 
    }
};