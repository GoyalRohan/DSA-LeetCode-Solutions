class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size() ; 
        int maxReach = startFuel  ,count = 0 , index = 0;
        priority_queue<int> pq ; 
        
        while(maxReach < target)
        {
            while(index < stations.size() && maxReach >= stations[index][0])
            {
                pq.push(stations[index][1]) ; 
                index++ ; 
            }
            
            if(pq.empty())
                return -1 ; 
            
            maxReach += pq.top() ; 
            pq.pop() ; 
            count++ ; 
        }
        
        return count ; 
        
    }
};