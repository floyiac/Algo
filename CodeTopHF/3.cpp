class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> charMap;
        int max_length = 0;
        int start = 0;
        for(int i=0; i<s.length();i++){
            if(charMap.find(s[i]) != charMap.end()){
                start = max(start,charMap[s[i]] + 1);
            }
            charMap[s[i]] = i;
            max_length = max(max_length,i-start+1);
        }
        return max_length;
    }
};