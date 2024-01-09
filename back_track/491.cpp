vector<vector<int>> res;
vector<int> path;
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        path.clear();
        backtrack(nums,0);
        return res;
    }

    void backtrack(vector<int>&nums, int index){
        if (path.size() > 1){
            res.push_back(path);
        }
        unordered_set<int> used;
        for(int i=index; i < nums.size(); i++){
            if ((!path.empty() && nums[i] < path.back()) || used.find(nums[i]) != used.end()){
                // element has been used or the element is smaller than in the path
                continue;
            }
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(nums,i+1);
            path.pop_back();
        }
    }
};
