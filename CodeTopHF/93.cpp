class Solution {
private:
    vector<string> result;
public:
    void backtrack(string& s,int startIndex, int pointNum){
        if(pointNum == 3){
            if(isValid(s,startIndex,s.size()-1)){
                result.push_back(s);
            }
            return ;
        }
        for(int i=startIndex;i<s.size();i++){
            if(isValid(s,startIndex,i)){
                s.insert(s.begin()+i+1,'.');
                pointNum++;
                backtrack(s,i+2,pointNum);
                pointNum--;
                s.erase(s.begin()+i+1);
            }
            else{
                break;
            }
        }
    }
    bool isValid(string&s, int start, int end){
        //[start,end]
        if(start > end){
            return false;
        }
        if(s[start] == '0'  && start != end){
            //no leading zero
            return false;
        }
        int num = 0;
        for(int i=start;i<=end;i++){
            if(s[i] > '9' || s[i] < '0'){
                //non number character
                return false;
            }
            num = 10 * num + s[i] - '0';
            if(num > 255){
                return false;
            }
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if(s.size() < 4 || s.size() > 12) return result;
        backtrack(s,0,0);
        return result;
    }
};