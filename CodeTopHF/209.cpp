class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = 0;
        int i = 0;
        int res = INT_MAX;
        int sum = 0;
        for(int j=0; j<nums.size();j++){
            sum += nums[j];
            while(sum >= target){
                length = j-i+1;
                res = res < length ? res : length;
                sum -= nums[i++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};