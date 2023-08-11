class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxpoint = 10001 ; 
        int n = points.size() ; 
        
        if(n <= 2)
            return n ; 
        
        int maxi = 2 ; 
        
        for(int i= 0; i<n-1 ; i++)
        {
            unordered_map<double , int> mpp ; 
            for(int j=0 ; j<n ; j++)
            {
                if(i == j)
                    continue ;
                
                if(points[j][0] == points[i][0])
                {
                     mpp[maxpoint]++ ;  
                }
                else
                {
                    double slope = double(points[j][1] - points[i][1]) / double(points[j][0] - points[i][0]) ; 
                    mpp[slope]++ ; 
                }
                
                
            }
            
            for(auto m : mpp)
            {
                maxi = max(maxi , m.second+1) ; 
            }
        }
        
        
        
        
        
        return maxi ; 
    }
};