class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, int target, int sum, int index){
        if(sum == target){
            res.push_back(path);
            return ;
        }
        if(sum > target){
            return ;
        }
        for(int i=index;i<candidates.size() && candidates[i] + sum <= target;i++){
            // avoid repetitive value
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates,target,sum,i+1);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        //sort the vector before backtracking to detect repetitive value
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,0);
        return res;
    }
};