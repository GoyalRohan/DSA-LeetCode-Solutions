class NumMatrix {
public:
    
    vector<vector<int>> sum ; 
    
    NumMatrix(vector<vector<int>>& matrix) {
        int r= matrix.size() , c = matrix[0].size() ; 
        sum = vector<vector<int>>(r+1 , vector<int>(c+1 , 0)) ; 
        
        for(int i=1 ; i<=r ; i++)
        {
            for(int j=1 ; j<=c ; j++)
            {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1] ; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1] ; 
        return ans ; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */