//Hash table solution
//think about using hash table when it is related with unique elements.
class Solution {
public:
    // value as key, i as value;
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> solution;
        for (int i=0; i < nums.size(); i++){
            auto it = solution.find(target - nums[i]);
            if(it != solution.end()){
                // finds the element
                return {it->second, i};
            }
            else{
                solution.insert(pair<int,int>(nums[i],i));
            }
        }
        return {};
    }
};
