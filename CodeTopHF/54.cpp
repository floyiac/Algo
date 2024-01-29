class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        vector<int> res;
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        while(top<=bottom && left <= right){
            for(int i=left;i<=right;i++){
                res.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    res.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            if(left<=right) {
                for (int j = bottom; j >= top; j--) {
                    res.push_back(matrix[j][left]);
                }
                left++;
            }
        }
        return res;
    }
};