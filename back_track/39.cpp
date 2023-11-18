class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int>& candidates, int target, int sum, int startindex){
        // recursion end conditions
        if(sum == target){
            res.push_back(path);
            return ;
        }
        if (sum > target){
            return ;
        }
        // backtrack logic
        for(int i=startindex; i< candidates.size(); i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates,target,sum,i);
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
