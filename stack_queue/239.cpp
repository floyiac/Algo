class Myqueue{
public:
    deque<int> que;
    void push(int value){
        while(!que.empty() && value > que.back()){
            que.pop_back();
        }
        que.push_back(value);
    }

    void pop(int value){
        if(!que.empty() && value == que.front()){
            que.pop_front();
        }
    }

    int front(){
        return que.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        Myqueue que;
        for(int i=0; i<k;i++){
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for(int i=k;i<nums.size();i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};