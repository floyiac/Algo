class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //sliding window;
        int sum=0;    //sum of the subarray;
        int length=0; //length of the subarray;
        int i=0; // left indice;
        int result = INT_MAX; //final result;
        for(int j=0; j<nums.size();j++){
            sum += nums[j];
            while(sum >=target){
                length = j-i+1;
                result = result<length? result : length; // takes the smaller one;
                sum -= nums[i++]; // i moves right 1 digit
            }
        }
        return result == INT_MAX? 0 : result;
    }
};
