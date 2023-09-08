class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> temp(n+1 , vector<int>(n+1 , 0)) ; 
        
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=i ; j++)
            {
                if(j==1 || j==i)
                    temp[i][j] = 1 ; 
                else
                {
                    temp[i][j] = temp[i-1][j-1] + temp[i-1][j] ; 
                }
            }
        }
        
        vector<vector<int>> ans ; 
        
        for(int i=1 ; i<=n ; i++)
        {
            vector<int> vec ; 
            for(int j=1 ; j<=i ; j++)
            {
                vec.push_back(temp[i][j]) ; 
            }
            ans.push_back(vec) ; 
        }
        
        return ans ; 
    }
};