class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int left = 0;
        int right = n-1;
        int top=0;
        int bottom = n-1;
        int num = 1;
        while(num<=n*n){
            //top row
            for(int i=left;i<=right;i++){
                res[top][i] = num;
                num++;
            }
            top++;
            //right row
            for(int i=top;i<=bottom;i++){
                res[i][right] = num;
                num++;
            }
            right--;
            //bottom row
            for(int i=right;i>=left;i--){
                res[bottom][i] = num;
                num++;
            }
            bottom--;
            //left row
            for(int i=bottom; i>=top;i--){
                res[i][left] = num;
                num++;
            }
            left++;
        }
        return res;
    }
};
