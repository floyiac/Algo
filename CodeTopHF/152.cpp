class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minP = nums[0];
        int maxP = nums[0];
        int res =  nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = maxP;
            maxP = max({nums[i],maxP*nums[i],minP*nums[i]});
            minP = min({nums[i],temp*nums[i],minP*nums[i]});
            res = max(res,maxP);
        }
        return res;
    }
};