class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> solution(nums.size(),0);
        int left = 0;
        int right = nums.size()-1;
        for(int i=0; i<nums.size();i++){
            if(nums[left]*nums[left] < nums[right]*nums[right]){
                solution[nums.size()-1-i] = nums[right]*nums[right];
                right--;
            }
            else{
                solution[nums.size()-1-i] = nums[left] * nums[left];
                left++;
            }
        }
        return solution;
    }
};
