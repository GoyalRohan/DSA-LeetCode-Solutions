class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        
        if(x+y < z)
            return false ; 
        
        queue<int> q ; 
        q.push(0); 
        unordered_map<int, bool> mpp ; 
        mpp[0] = true ; 
        
        vector<int> dx = {x , -x , y , -y} ; 
        
        while(!q.empty())
        {
            int node = q.front() ; 
            q.pop() ; 
            if(node == z)
                return true ; 
            
            for(int i=0 ; i<4 ; i++)
            {
                int temp = node + dx[i] ; 
                
                if(temp<0 || temp>x+y || mpp.find(temp) != mpp.end())
                    continue ; 
                
                if(temp == z)
                    return true ; 
                
                q.push(temp) ; 
                mpp[temp] = true ; 
            }
            
        }
        
        return false; 
        
    }
};