class Solution {
public:
    
    int dp[101][101]{};
    
    int UniquePaths(int m, int n, int i , int j) {
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = UniquePaths(m, n, i+1, j) + UniquePaths(m, n, i, j+1);
    }
    
    int uniquePaths(int m, int n) {
        return UniquePaths(m , n , 0 , 0) ; 
    }
};