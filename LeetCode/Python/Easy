217. Contains Duplicate
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

