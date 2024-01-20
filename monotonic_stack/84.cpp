class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        int res = 0;
        st.push(0);
        for(int i=1;i<heights.size();i++){
            while(heights[i]<heights[st.top()]){
                int mid = st.top();
                st.pop();
                int w = i - st.top() - 1; // the middle area
                int h = heights[mid];
                res = max(res,w*h);
            }
            st.push(i);
        }
        return res;
    }
};