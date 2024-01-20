class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
public:
    void dfs(vector<vector<int>>& graph, int x){
        if(x == graph.size() - 1){
            res.push_back(path);
            return ;
        }
        for(int i=0; i <graph[x].size(); i++){
            path.push_back(graph[x][i]);
            dfs(graph,graph[x][i]);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph,0);
        return res;
    }
};