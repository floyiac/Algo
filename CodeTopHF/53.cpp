class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            count += nums[i];
            if(count > res){
                res = count;
            }
            if(count <0){
                count = 0;
            }
        }
        return res;
    }
};