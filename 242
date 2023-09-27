class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for(int i=0; i<s.size();i++){
            record[s[i] - 'a']++;
        }
        for(int j=0; j<t.size();j++){
            record[t[j] - 'a']--;
        }
        for(int k=0; k<26;k++){
            if(record[k]!=0){
                return false;
            }
        }
        return true;
    }
};
