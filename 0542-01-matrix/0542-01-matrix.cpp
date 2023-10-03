class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size() ; 
        vector<vector<int>> dist(m , vector<int>(n, 0)) ; 
        
        queue<pair<pair<int, int> , int>> q ; 
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j} , 0}) ; 
                    dist[i][j] = 0 ; 
                }
            }
        }
        
        int dx[4] = {0 , 0 , 1 , -1} ; 
        int dy[4] = {1 , -1 , 0 , 0} ; 
         
        
        while(!q.empty()) 
        {
            int i = q.front().first.first ; 
            int j = q.front().first.second ; 
            int steps = q.front().second ; 
            q.pop() ; 
            
            
            dist[i][j] = steps ; 
            
            for(int k=0 ; k<4 ; k++)
            {
                int newi = i+dx[k] , newj = j+dy[k] ; 
                // cout<<"Fsfsfref" ; 
                if(newi>=0 && newi<m && newj>=0 && newj<n && mat[newi][newj] == 1)
                {
                    mat[newi][newj] = 0 ; 
                    q.push({{newi, newj} , steps+1}) ; 
                }
            }
            
        }
        
        return dist ; 

    }
};