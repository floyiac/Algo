//Annotation
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26] = {0}; //ransom 
        int b[26] = {0}; //magazine
        for(int j=0; j<magazine.size();j++){
            b[magazine[j]-'a']++;
        }
        for(int i=0; i<ransomNote.size();i++){
            a[ransomNote[i]-'a']++;
        }
        for(int k=0;k<26;k++){
            if(a[k] > b[k]){
                return false;
            }
        }
        return true;
    }
};
