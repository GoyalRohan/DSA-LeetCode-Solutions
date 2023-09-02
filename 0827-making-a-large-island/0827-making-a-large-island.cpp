class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j,int &color){//Marking all islands with a soecific 'color'
        int row[]={+1,0,-1,0},col[]={0,+1,0,-1};
        grid[i][j]=color;
        int c=0;
        for(int k=0;k<4;k++){
            int newRow=i+row[k],newCol=j+col[k];
            if(newRow>=0&&newCol>=0&&newRow<grid.size()&&newCol<grid[0].size()&&grid[newRow][newCol]==1){                
                c+=1+dfs(grid,newRow,newCol,color);                
            }
        }
        return c;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        int color=2;// Start coloring from 2 since 1 indicates island
        unordered_map<int,int>m1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    m1[color++]=dfs(grid,i,j,color)+1;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>ds;
                    int row[]={+1,0,-1,0},col[]={0,+1,0,-1};
                    for(int k=0;k<4;k++){
                        int newRow=i+row[k],newCol=j+col[k];
                        if(newRow>=0&&newCol>=0&&newRow<grid.size()&&newCol<grid[0].size()&&grid[newRow][newCol]!=0){
                            ds.insert(grid[newRow][newCol]);
                        }
                    }
                    int s=1;
                    for(auto i:ds)
                        s+=m1[i];
                    ans=max(ans,s);
                }
            }
        }
        return ans==0?m*n:ans;
    }
};