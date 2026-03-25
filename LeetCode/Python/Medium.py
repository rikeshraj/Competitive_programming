# 2. Add Two Numbers
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        dummy = ListNode(0)
        current = dummy
        carry = 0
        while l1 or l2 or carry: 
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            current.next = ListNode(carry%10)
            carry //= 10
            current = current.next 
        return dummy.next


# 1461. Check If a String Contains All Binary Codes of Size K
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        if len(s) < (1 << k):
            return False
        see = {s[i:i+k] for i in range(len(s)-k+1)}
        return len(see) == (1 << k)


# 3546. Equal Sum Grid Partition I
class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        total_sum = sum(sum(row) for row in grid)
        if total_sum%2 != 0:
            return False
        target = total_sum//2
        m, n = len(grid), len(grid[0])
        row_sum = 0
        for i in range(m-1):
            row_sum += sum(grid[i])
            if row_sum == target:
                return True
        col_sum = 0
        for j in range(n-1): 
            for i in range(m):
                col_sum += grid[i][j]
            if col_sum == target:
                return True
        return False


# 3713. Longest Balanced Substring I
class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        max_len = 0
        for i in range(n):
            counts = [0]*26
            distinct_char = 0
            for j in range(i, n):
                char_id = ord(s[j])-ord('a')
                if counts[char_id] == 0:
                    distinct_char += 1
                counts[char_id] += 1
                current_len = j-i+1
                if current_len%distinct_char == 0:
                    target_count = current_len//distinct_char
                    is_balanced = True
                    for k in range(26):
                        if counts[k]>0 and counts[k]!=target_count:
                            is_balanced = False
                            break
                    if is_balanced:
                        max_len = max(max_len, current_len)
        return max_len
