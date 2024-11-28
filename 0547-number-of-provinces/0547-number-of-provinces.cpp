class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adjL){
        visited[node]=1;
        for(auto it : adjL[node]){
            if (!visited[it]){
                dfs(it,visited,adjL);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adjL(n);
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected.size(); j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        vector<int>visited(n,0);
        int count = 0;
        for(int i=0; i<adjL.size(); i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adjL);
            }
        }
        return count;
    }
};