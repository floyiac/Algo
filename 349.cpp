class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> store(nums1.begin(),nums1.end());
        for(int ele : nums2){
            //finds the element both arrays share
            //insert
            if(store.find(ele) != store.end()){
                res.insert(ele);
            }
        }
        return vector<int> (res.begin(),res.end());
    }
};
