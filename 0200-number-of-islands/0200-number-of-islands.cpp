class Solution {
public:
    void bfs(int row, int col ,vector<vector<int>> &visited,vector<vector<char>>& grid){
        visited[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row_f =q.front().first;
            int col_f = q.front().second;
            q.pop();
            int delrow[]={-1,1,0,0};
            int delcol[]={0,0,-1,1};
            for(int k=0; k<4; k++){
                    int new_row = delrow[k]+row_f;
                    int new_col = delcol[k]+col_f;
                    if(new_row>=0 && new_row<grid.size() && new_col>=0 && new_col<grid[0].size() && grid[new_row][new_col]=='1'){
                        grid[new_row][new_col] = '0';
                        q.push({new_row,new_col});
                    }
                
            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col]=='1'){
                    count++;
                    bfs(row,col,visited,grid);
                }
            }
        }
        return count;
    }
};