class Solution {
private:
    int count;
    int dir[4][2] = {0,1,1,0,-1,0,0,-1};
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
        for(int i=0; i<4; i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(nextx < 0 || nextx >= grid.size() || nexty <0 || nexty >= grid[0].size()) continue;
            if(!visited[nextx][nexty] && grid[nextx][nexty] == 1){
                visited[nextx][nexty] = true;
                count++;
                dfs(grid,visited,nextx,nexty);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res =  0;

        vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(m, false));

        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    count = 1;
                    visited[i][j] = true;
                    dfs(grid,visited,i,j);
                    res = max(res,count);
                }
            }
        }
        return res;
    }
};