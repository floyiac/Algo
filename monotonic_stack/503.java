class Solution {
    public int[] nextGreaterElements(int[] nums) {
        if(nums.length <= 1){
            return new int[]{-1};
        }
        int[] res = new int[nums.length];
        Arrays.fill(res,-1);
        int size = nums.length;
        Stack<Integer> st = new Stack<>();
        for(int i=0; i<2*size; i++){
            while(!st.isEmpty() && nums[i%size] > nums[st.peek()]){
                res[st.peek()] = nums[i%size];
                st.pop();
            }
            st.push(i%size);
        }
        return res;
    }
}