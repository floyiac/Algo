class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i=0; i<nums1.length;i++){
            map.put(nums1[i],i);
        }
        int[] res = new int[nums1.length];
        Arrays.fill(res,-1);
        Stack<Integer> stack = new Stack<>();
        for(int j=0; j<nums2.length; j++){
            while(!stack.isEmpty() && nums2[j] > nums2[stack.peek()]){
                int pre = nums2[stack.pop()];
                if (map.containsKey(pre)){
                    res[map.get(pre)] = nums2[j];
                }
            }
            stack.push(j);
        }
        return res;
    }
}