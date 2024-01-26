class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[left] <= nums[mid]){
                // left half is sorted
                if(nums[mid] > target && target >= nums[left]){
                    // target possibly lies in left half
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                //right half is sorted
                if(nums[mid] < target && target <= nums[right]){
                    //target possibly lies in right half
                    left = mid + 1;
                }
                else{
                    right = mid -1;
                }
            }
        }
        return -1;
    }
};