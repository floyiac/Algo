class Solution {
private:
    int count;
    int dir[4][2] = {0,1,1,0,-1,0,0,-1};
public:
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
        queue<int> que;
        que.push(x);
        que.push(y);
        visited[x][y] = true;
        count++;
        while(!que.empty()){
            int xx = que.front();
            que.pop();
            int yy = que.front();
            que.pop();
            for(int i=0;i<4;i++){
                int nextx = xx + dir[i][0];
                int nexty = yy + dir[i][1];
                if(nextx<0 || nexty<0 || nextx >= grid.size() || nexty >= grid[0].size()){
                    continue;
                }
                if(!visited[nextx][nexty] && grid[nextx][nexty] == 1 ){
                    visited[nextx][nexty] = true;
                    count++;
                    que.push(nextx);
                    que.push(nexty);
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    count = 0;
                    bfs(grid,visited,i,j);
                    res = max(res,count);
                }
            }
        }
        return res;
    }
};