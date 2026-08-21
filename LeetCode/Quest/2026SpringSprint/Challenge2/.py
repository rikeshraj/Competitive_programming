'''
Q1. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
'''
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_sum = 0
        count = 0
        freq = {0: 1}
        for num in nums:
            prefix_sum += num
            if prefix_sum - k in freq:
                count += freq[prefix_sum - k]
            freq[prefix_sum] = freq.get(prefix_sum, 0) + 1
        return count

'''
Q2. Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
'''
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

'''
Q3. Minimum Operations to Reduce an Integer to 0
You are given a positive integer n, you can do the following operation any number of times:
Add or subtract a power of 2 from n.
Return the minimum number of operations to make n equal to 0.
A number x is power of 2 if x == 2i where i >= 0.
'''
class Solution:
    def minOperations(self, n: int) -> int:
        ans = 0
        while n > 0:
            if (n & 3) == 3:
                n += 1
                ans += 1
            elif n & 1:
                n -= 1
                ans += 1
            else:
                n >>= 1
        return ans

