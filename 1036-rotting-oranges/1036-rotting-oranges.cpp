class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        int time = 0;
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t   = q.front().second;
            q.pop();
            time = max(time,t);
            for(int k=0; k<4; k++){
                int new_row = row+delrow[k];
                int new_col = col+delcol[k];
                if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && visited[new_row][new_col]!=2 && grid[new_row][new_col]==1){
                    q.push({{new_row,new_col},t+1});
                    visited[new_row][new_col]=2;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};