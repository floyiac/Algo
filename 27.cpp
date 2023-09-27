int slow = 0;
for(int fast=0; fast<nums.size();fast++){if(nums[fast] != val){nums[slow] = nums[fast];slow++;}}
return slow;
