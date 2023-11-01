//Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solution;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >0){
                // no solution in this case
                return solution;
            }
            if(i >0 && nums[i] == nums[i-1]){
                //avoid repetition of a
                continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            while(right > left){
                if(nums[i] + nums[right] + nums[left] == 0){
                    // find one solution;
                    solution.push_back(vector<int>{nums[i],nums[right],nums[left]});
                    while(right > left && nums[left] == nums[left + 1]){
                        //avoid repetition of b
                        left ++;
                    }
                    while(right > left && nums[right] == nums[right - 1]){
                        //avoid repetition of c
                        right--;
                    }
                    left ++;
                    right--;
                }
                else if(nums[i] + nums[right] + nums[left] <0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return solution;
    }
};
