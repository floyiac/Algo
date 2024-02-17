class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int index){
        res.push_back(path);
        if(index >= nums.size()){
            return ;
        }
        for(int i=index;i<nums.size();i++){
            path.push_back(nums[i]);
            backtrack(nums,++index);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        res.clear();
        backtrack(nums,0);
        return res;
    }
};