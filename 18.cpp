class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> solution;
        for(int i=0; i<nums.size();i++){
            if(nums[i] > target && nums[i] >= 0){
                break;
            }
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] > target && nums[j] + nums[i]>= 0){
                    break;
                }
                if(j >i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int left = j+1;
                int right = nums.size() - 1;
                while( right > left){
                    if((long)nums[i]+nums[j]+nums[right]+nums[left] > target){
                        right --;
                    }
                    else if((long)nums[i]+nums[j]+nums[right]+nums[left] < target){
                        left ++;
                    }
                    else{
                        solution.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        while(right > left && nums[left] == nums[left+1]){
                            left++;
                        }
                        while(right >left && nums[right] == nums[right - 1]){
                            right --;
                        }
                        left ++;
                        right --;
                    }
                }
            }   
        }
        return solution;
    }
};
