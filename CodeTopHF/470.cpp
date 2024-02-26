// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // map [1,7] to [1,49], [1,49] to [1,40]
        int n = rand7();
        int m = rand7();
        int temp = n + (m-1)*7;
        if(temp <= 40){
            return 1 + (temp-1)%10; //[1,10]
        }
        return rand10();
    }
};