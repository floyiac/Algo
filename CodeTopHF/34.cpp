class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int left = 0;
        int right = nums.size() -1 ;
        vector<int> res;
        while(left <= right){
            if(nums[left] == target && nums[right] == target){
                res.push_back(left);
                res.push_back(right);
                return res;
            }
            else if(nums[left] == target && nums[right] != target){
                right--;
            }
            else if(nums[left] !=target && nums[right] == target){
                left++;
            }
            else{
                right--;
                left++;
            }
        }
        return {-1,-1};
    }
};