// 1. Two Sum 
class Solution {
    public int[] twoSum(int[] nums, int target) {
        java.util.HashMap<Integer, Integer> map = new java.util.HashMap<>();
        for(int i=0; i<nums.length; i++) {
            int com = target-nums[i];
            if(map.containsKey(com)) { 
                return new int[] {map.get(com), i};
            }
            map.put(nums[i], i);
        }
            return new int[] {};
    }
}


//190. Reverse Bits
class Solution {
    public int reverseBits(int n) {
        int res = 0;
        for(int i=0; i<32; ++i) {
            res = (res<<1) | (n&1);
            n >>= 1;
        }
        return res;
    }
}


