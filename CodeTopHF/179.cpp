class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto compare = [](const string& x, const string& y){
            return (x+y) > (y+x);
        };
        vector<string> string_nums;
        for(int num : nums){
            string_nums.push_back(to_string(num));
        }
        sort(string_nums.begin(),string_nums.end(),compare);
        string result;
        for(const string& temp : string_nums){
            result += temp;
        }
        if(result[0] == '0'){
            return "0";
        }
        return result;
    }
};