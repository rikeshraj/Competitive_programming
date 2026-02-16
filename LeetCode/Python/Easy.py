#110. Balanced Binary Tree
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def check_height(node):
            if not node:
                return 0
            left_height = check_height(node.left)
            if left_height == -1:
                return -1
            right_height = check_height(node.right)
            if right_height == -1:
                return -1
            if abs(left_height-right_height)>1:
                return -1
            return 1+max(left_height, right_height)
        return check_height(root) != -1


# 190. Reverse Bits
class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            res <<= 1
            res |= (n&1)
            n >>= 1
        return res


#217. Contains Duplicate
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums_len = len(nums)
        nums = set(nums)
        if len(nums) != nums_len:
            return True
        return False
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums_copy = set()
        for i in nums:
            nums_copy.add(i)
        if len(nums) > len(nums_copy):
            return True
        return False


#3010. Divide an Array Into Subarrays With Minimum Cost I 
class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        first_cost = nums[0]
        rem_nums = nums[1:]
        rem_nums.sort()
        second_cost = rem_nums[0]
        third_cost = rem_nums[1]
        min_total_cost = first_cost+second_cost+third_cost
        return min_total_cost
