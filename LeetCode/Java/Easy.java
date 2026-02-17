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

// 9. Palindrome Number 
class Solution {
    public boolean isPalindrome(int x) {
        long copy = x;
        long rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return copy == rev;
    }
}

// 110. Balanced Binary Tree
class Solution {
    private int checkHeight(TreeNode node) {
        if (node == null) return 0;
        int leftHeight = checkHeight(node.left);
        if (leftHeight == -1) return -1;
        int rightHeight = checkHeight(node.right);
        if (rightHeight == -1) return -1;
        if (Math.abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + Math.max(leftHeight, rightHeight);
    }
    public boolean isBalanced(TreeNode root) {
        return checkHeight(root) != -1;
    }
}


// 190. Reverse Bits
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


// 217. Contains Duplicate
class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (!set.add(num)) {
                return true;
            false;
    }
}


// 3010. Divide an Array Into Subarrays With Minimum Cost I 
class Solution {
    public int minimumCost(int[] nums) {
        int firstCost = nums[0];
        Arrays.sort(nums, 1, nums.length);
        int secondCost = nums[1];
        int thirdCost = nums[2];
        return firstCost + secondCost + thirdCost;
    }
}


// 


// 

