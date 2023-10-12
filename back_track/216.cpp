class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void back_track(int k, int n, int sum, int startIndex){
        if(sum == n){
            if(path.size() == k){res.push_back(path);}
            return ;
        }
        for(int i=startIndex; i<=9; i++){
            sum += i;
            path.push_back(i);
            back_track(k,n,sum,i+1);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        back_track(k,n,0,1);
        return res;
    }
};
