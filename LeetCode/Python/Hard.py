# 4. Median of Two Sorted Arrays
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        m = len(nums1)
        n = len(nums2)
        left = 0
        right = m
        half = (m + n + 1) // 2
        while left <= right:
            i = (left + right) // 2
            j = half - i
            Aleft = nums1[i - 1] if i > 0 else float('-inf')
            Aright = nums1[i] if i < m else float('inf')
            Bleft = nums2[j - 1] if j > 0 else float('-inf')
            Bright = nums2[j] if j < n else float('inf')
            if Aleft <= Bright and Bleft <= Aright:
                if (m + n) % 2 == 1:
                    return max(Aleft, Bleft)
                return (
                    max(Aleft, Bleft) +
                    min(Aright, Bright)
                ) / 2
            elif Aleft > Bright:
                right = i - 1
            else:
                left = i + 1

# 23. Merge k Sorted Lists
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        for i, node in enumerate(lists):
            if node:
                heapq.heappush(heap, (node.val, i, node))
        dummy = ListNode(0)
        current = dummy
        while heap:
            value, i, node = heapq.heappop(heap)
            current.next = node
            current = current.next
            if node.next:
                heapq.heappush(
                    heap,
                    (node.next.val, i, node.next)
                )
        return dummy.next

# 42. Trapping Rain Water
class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        left_max = 0
        right_max = 0
        water = 0
        while left < right:
            if height[left] <= height[right]:
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    water += left_max - height[left]
                left += 1
            else:
                if height[right] >= right_max:
                    right_max = height[right]
                else:
                    water += right_max - height[right]
                right -= 1
        return water

# 85. Maximal Rectangle
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        cols = len(matrix[0])
        heights = [0] * cols
        max_area = 0
        for row in matrix:
            for j in range(cols):
                if row[j] == '1':
                    heights[j] += 1
                else:
                    heights[j] = 0
            stack = [-1]
            for i in range(cols + 1):
                current = heights[i] if i < cols else 0
                while stack[-1] != -1 and heights[stack[-1]] > current:
                    h = heights[stack.pop()]
                    width = i - stack[-1] - 1
                    max_area = max(max_area, h * width)
                stack.append(i)
        return max_area

# 761. Special Binary String
class Solution(object):
    def makeLargestSpecial(self, s):
        """
        :type s: str
        :rtype: str  
        """ 
        count = 0 
        i = 0  
        res = [] 
        for j, char in enumerate(s): 
            if char == '1':
                count += 1 
            else: 
                count -= 1
            if count == 0: 
                res.append('1' + self.makeLargestSpecial(s[i+1:j]) + '0')
                i = j+1
        res.sort(reverse = True)
        return "".join(res)
