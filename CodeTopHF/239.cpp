class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> D;
        for(int i=0;i<nums.size();i++) {
            //remove out of bound elements
            if(!D.empty() && i-D.front() >= k){
                D.pop_front();
            }
            //remove elements that are smaller than nums[i]
            while(!D.empty() && nums[i] > nums[D.back()]){
                D.pop_back();
            }
            D.push_back(i);
            if(i >= k-1) res.push_back(nums[D.front()]);
        }
        return res;
    }
};