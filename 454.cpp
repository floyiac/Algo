class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> solution;
        for(int a : nums1){
            for(int b : nums2){
                auto it = solution.find(a+b);
                if( it != solution.end()){
                    it->second += 1;
                }
                else{
                    solution.insert(pair<int,int>{a+b,1});
                }
            }
        }

        int count = 0;

        for(int c : nums3){
            for (int d : nums4){
                auto it = solution.find(0 - (c+d));
                if(it != solution.end()){
                    count += it->second;
                }
            }
        }
        return count;
    }
};
