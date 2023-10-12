class Solution {
private:
    string stringmap[10] = {
        "", // 0
        "", // 1
        "abc",//2
        "def",//3
        "ghi",//4
        "jkl",//5
        "mno",//6
        "pqrs",//7
        "tuv",//8
        "wxyz",//9
    };
public:
    vector<string> res;
    string s;
    void back_track(string& digits, int index){
        if(digits.size() == index){
            res.push_back(s);
            return ;
        }
        int digit = digits[index] - '0';
        string letter = stringmap[digit];
        for(int i=0; i<letter.size();i++){
            s.push_back(letter[i]);
            back_track(digits,index+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return res;
        }
        back_track(digits,0);
        return res;
    }
};
