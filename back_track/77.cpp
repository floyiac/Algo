class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void back_track(int n, int k, int startIndex){
        if(path.size() == k){
            result.push_back(path);
            return ;
        }
        for(int i=startIndex; i<=n ;i++){
            path.push_back(i);
            back_track(n,k,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        back_track(n,k,1);
        return result;
    }
};
