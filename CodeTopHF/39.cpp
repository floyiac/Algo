class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, int target, int index, int sum){
        if(sum > target) return;
        if(sum == target){
            res.push_back(path);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates,target,i,sum);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        backtrack(candidates,target,0,0);
        return res;
    }
};