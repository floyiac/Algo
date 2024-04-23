class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        long long res = 0;
        while(x>0){
            int digit = x % 10;
            res = 10*res + digit;
            x = x/10;
        }
        return original == res;
    }
};