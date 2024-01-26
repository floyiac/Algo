class Solution {
    // bfs version
private:
    int dir[4][2] = {0,1,1,0,0,-1,-1,0};
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        queue<pair<int,int>> que;
        que.push({x,y});
        visited[x][y] = true;
        while(!que.empty()){
            pair<int,int> cur = que.front();
            que.pop();
            int curx = cur.first;
            int cury = cur.second;
            for(int i=0;i<4;i++){
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if(nextx<0 || nexty <0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;
                if(!visited[nextx][nexty] && grid[nextx][nexty] == '1'){
                    que.push({nextx,nexty});
                    visited[nextx][nexty] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    res++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return res;
    }
};