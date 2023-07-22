class Solution {
public:
    
    // int solve(int i, int j , int k )    
        
    bool isValid(int i , int j , int n , int k)
    {
        if(i <0 || i>=n || j<0 || j>=n)
            return false ; 
        return true ; 
    }
    
    unordered_map<string, double> mpp ; 
    
    double knightProbability(int n, int k, int row, int column) {
        
        if(isValid(row , column , n , k) == false)
            return 0.0 ; 
        
        if(k == 0)
            return 1 ;
        
        string key = to_string(k) + "_" + to_string(row) + "_" + to_string(column) ;
        
        if(mpp.find(key) != mpp.end()) 
            return mpp[key] ; 
        
        vector<int> dx {2 , 2 , -2 , -2 , 1 , 1 , -1 , -1} ; 
        vector<int> dy{1 , -1 , 1 , -1 , 2 , -2 , 2 , -2} ; 
        
        double sum = 0.0 ; 
        
        for(int i=0 ; i<8 ; i++)
        {
            sum += knightProbability(n , k-1 , row+dx[i] , column + dy[i]) ; 
        }
        

        return mpp[key] =  (double)sum/8 ; 
        
    }
};