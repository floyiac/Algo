vector<int> path;
vector<vector<int>> res;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        path.clear();
        res.clear();
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return res;
    }
    void backtrack(vector<int>& nums, int index){
        res.push_back(path);
        for(int i=index; i<nums.size(); i++){
            if (i>index && nums[i] == nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            backtrack(nums,i+1);
            path.pop_back();
        }
    }
};