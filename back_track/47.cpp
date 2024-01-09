class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        backtrack(nums,used);
        return res;
    }

    void backtrack(vector<int>& nums, vector<bool>& used){
        if (path.size() == nums.size()){
            res.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if (i>0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            if (!used[i]){
                used[i] = true;
                path.push_back(nums[i]);
                backtrack(nums,used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};