class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int left = 1, right = x, ans = 0;
        while(left <= right){
            long mid = left + (right-left) / 2;
            if(mid * mid == x){
                return mid;
            }
            else if(mid * mid < x){
                left = mid + 1;
                ans = mid;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};