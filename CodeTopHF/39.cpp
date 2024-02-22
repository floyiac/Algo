class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int>& candidates, int target, int sum, int index){
        if(sum > target) return;
        if(sum == target){
            res.push_back(path);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates,target,sum,i);
            path.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        backtrack(candidates,target,0,0);
        return res;
    }
};