class Solution {
public:
    vector<string> res;
    void backtrack(string& s, int index, int comma_num){
        if(comma_num == 3){
            // number of comma is 3
            if(isValid(s,index,s.size()-1)){
                res.push_back(s);
            }
            return ;
        }
        for(int i=index; i<s.size();i++){
            if (isValid(s, index, i)) {
                // i + 1 insertion .
                s.insert(s.begin()+i+1,'.');
                comma_num ++;
                backtrack(s,i+2,comma_num); // i+1 . starts at i+2
                comma_num --;
                s.erase(s.begin()+i+1);
            }
            else {
                break;
            }
        }
    }
    bool isValid(string& s, int start, int end){
        if(start > end){
            return false;
        }
        if(s[start] == '0' && start != end){
            // no leading zero
            return false;
        }
        int num = 0;
        for(int i=start; i<=end;i++){
            if(s[i] > '9' || s[i] < '0'){
                // contains elements other than number
                return false;
            }
            num  = num *10 + (s[i] - '0');
            if(num > 255){
                return false;
            }
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        backtrack(s,0,0);
        return res;
    }
};