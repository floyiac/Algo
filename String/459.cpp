class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s+s;
        temp.erase(temp.begin());
        temp.erase(temp.end()-1);
        if(temp.find(s) != std::string::npos ) return true;
        // ！= -1
        return false;
    }
};


