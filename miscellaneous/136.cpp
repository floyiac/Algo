class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(const int e : nums){
            res ^= e;
        }
        return res;
    }
};