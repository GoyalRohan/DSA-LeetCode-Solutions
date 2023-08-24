class Solution {
public:
    void dfs(int i, int j, int &oldcolor, int &newcolor, int &x, int &y ,vector<vector<bool>> &vis , vector<vector<int>>& image)
    {
        if(i <0 || j<0 || i>=x || j>=y)
            return ;
        
        if(vis[i][j] == true || image[i][j] != oldcolor)
            return ;
        
        vis[i][j] = true ; 
        image[i][j] = newcolor ; 
        
        dfs(i-1 , j, oldcolor, newcolor, x , y, vis, image) ; 
        dfs(i+1 , j, oldcolor, newcolor, x , y, vis, image) ; 
        dfs(i , j-1, oldcolor, newcolor, x , y, vis, image) ; 
        dfs(i , j+1, oldcolor, newcolor, x , y, vis, image) ; 
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x = image.size() ; 
        int y = image[0].size() ; 
        
        vector<vector<bool>> vis(x , vector<bool> (y , false)) ; 
        int oldcolor = image[sr][sc] ; 
        
        dfs(sr , sc , oldcolor, newColor , x , y , vis , image) ; 
        return image ; 
    }
};