class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for(char x : s){
            if(res.empty() || res.back() != x){
                // empty push; two different char push
                res.push_back(x);
            }
            else{
                // eliminate duplicate elements
                res.pop_back();
            }
        }
        return res;
    }
};
