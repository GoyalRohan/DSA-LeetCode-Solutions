class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxreach = startFuel, count = 0 , index = 0 ; 
        priority_queue<int> pq ; 
        
        while(maxreach < target)
        {
            while(index < stations.size() && maxreach >= stations[index][0])
            {
                pq.push(stations[index][1]) ; 
                index++ ; 
            }
            
            if(pq.empty())
                return -1 ; 
            
            maxreach += pq.top() ; 
            pq.pop() ; 
            count++ ; 
        }
        
        return count ; 
        
    }
};