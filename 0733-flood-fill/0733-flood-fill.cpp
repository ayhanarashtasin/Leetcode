class Solution {
public:
    void dfs(int row, int col , vector<vector<int>> &output ,vector<vector<int>>& image,int start_color,int color){
        output[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};
        for(int k=0; k<4; k++){
            int new_row = row+delrow[k];
            int new_col = col+delcol[k];
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && output[new_row][new_col]!=color && image[new_row][new_col]==start_color){
                dfs(new_row,new_col,output,image,start_color,color);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc]==color){
            return image;
        }
        int start_color = image[sr][sc];
        vector<vector<int>>output = image;
        dfs(sr,sc,output,image,start_color,color);
        return output;
    }
};