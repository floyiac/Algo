class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
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
        res.clear();
        path.clear();
        backtrack(nums,0);
        return res;
    }
};