class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int count = 1;
        if(nums.size() <= 1){
            return nums.size();
        }
        int cur = 0;
        int pre = 0 ;
        for(int i=0;i<nums.size()-1;i++){
            cur = nums[i+1] - nums[i];
            if((pre<=0 && cur >0) || (pre>=0 && cur<0)){
                count ++;
                pre = cur;
            }
        }
        return count;
    }
};