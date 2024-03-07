class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> nums_set(nums.begin(),nums.end());
        int maxStreak = 0;
        for(int num : nums){
            if(!nums_set.count(num - 1)){
                int curr = num;
                int curr_streak = 1;
                while(nums_set.count(curr+1)){
                    curr += 1;
                    curr_streak +=1;
                }
                maxStreak = max(maxStreak,curr_streak);
            }
        }
        return maxStreak;
    }
};