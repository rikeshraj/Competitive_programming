# 1. Two Sum
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = {}
        for i, n in enumerate(nums):
            com = target-n
            if com in res:
                return [res[com], i]
            res[n] = i


# 9. Palindrome Number
def isPalindrome(self, x: int) -> bool:
    copy = x
    rev = 0
    while x > 0:
        rev = rev * 10 + x % 10
        x //= 10
    return copy == rev


# 13. Roman to Integer
class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50,
            'C': 100, 'D': 500, 'M': 1000
        }
        total = 0
        prev = 0
        for ch in reversed(s):
            val = roman[ch]
            if val < prev:
                total -= val
            else:
                total += val
                prev = val
        return total


# 14. Longest Common Prefix
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        prefix = strs[0]
        for s in strs[1:]:
            while not s.startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return ""
        return prefix


# 20. Valid Parentheses
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {")": "(", "}": "{", "]": "["}
        for char in s:
            if char in mapping:
                top_element = stack.pop() if stack else '#'
                if mapping[char] != top_element:
                    return False
            else:
                stack.append(char)
        return not stack


# 21. Merge Two Sorted Lists
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        tail = dummy
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        tail.next = list1 if list1 else list2
        return dummy.next


# 26. Remove Duplicates from Sorted Array
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        k = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[k - 1]:
                nums[k] = nums[i]
                k += 1
        return k


# 27. Remove Element
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        return k


# 28. Find the Index of the First Occurrence in a String
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)
        if m == 0:
            return 0
        for i in range(n - m + 1):
            if haystack[i:i+m] == needle:
                return i
        return -1


# 35. Search Insert Position
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return left


# 58. Length of Last Word
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1
        while i >= 0 and s[i] == ' ':
            i -= 1
        length = 0
        while i >= 0 and s[i] != ' ':
            length += 1
            i -= 1
        return length


# 110. Balanced Binary Tree
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


# 217. Contains Duplicate
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums_len = len(nums)
        nums = set(nums)
        if len(nums) != nums_len:
            return True
        return False
#OR
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums_copy = set()
        for i in nums:
            nums_copy.add(i)
        if len(nums) > len(nums_copy):
            return True
        return False


# 401. Binary Watch 
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        return [f"{h}:{m:02d}" for h in range(12) for m in range(60) if(bin(h).count('1') + bin(m).count('1')) == turnedOn]


# 693. Binary Number with Alternating Bits
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        res = n ^ (n >> 1)
        return (res & (res+1)) == 0


# 696. Count Binary Substrings 
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        previous_count = 0
        current_count = 1
        count = 0
        for i in range(1, len(s)):
            if s[i] == s[i-1]: 
                current_count += 1 
            else:
                count += min(previous_count, current_count)
                previous_count = current_count 
                current_count = 1
        count += min(previous_count, current_count)
        return count


# 762. Prime Number of Set Bits in Binary Representation
class Solution(object):
    def countPrimeSetBits(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        def is_prime(n):
            if n<= 1:
                return False
            for i in range(2, int(n**0.5) + 1):
                if n%i == 0:
                    return False
            return True
        count = 0
        for i in range(left, right+1):
            set_bits = bin(i).count('1')
            if is_prime(set_bits):
                count += 1
        return count


# 868. Binary Gap
class Solution:
    def binaryGap(self, n: int) -> int:
        binary_str = bin(n)[2:]
        max_dis = 0
        last_index = -1
        for i, char in enumerate(binary_str):
            if char ==  '1':
                if last_index != -1:
                    max_dis = max(max_dis, i-last_index)
                last_index = i
        return max_dis


# 2078. Two Furthest Houses With Different Colors
class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        dist1 = 0
        for j in range(n-1, -1, -1):
            if colors[j] != colors[0]:
                dist1 = j
                break
        dist2 = 0
        for i in range(n):
            if colors[i] != colors[n-1]:
                dist2 = (n-1) - i
                break    
        return max(dist1, dist2)


# 2833. Furthest Point From Origin
class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        L = moves.count('L')
        R = moves.count('R')
        U = moves.count('_')
        return abs(R - L) + U


# 3010. Divide an Array Into Subarrays With Minimum Cost I 
class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        first_cost = nums[0]
        rem_nums = nums[1:]
        rem_nums.sort()
        second_cost = rem_nums[0]
        third_cost = rem_nums[1]
        min_total_cost = first_cost+second_cost+third_cost
        return min_total_cost


# 




