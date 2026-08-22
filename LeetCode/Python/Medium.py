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

# 22. Generate Parentheses
class Solution:
    def generateParenthesis(self, n):
        result = []
        def backtrack(s, open_count, close_count):
            if len(s) == 2 * n:
                result.append(s)
                return
            if open_count < n:
                backtrack(
                    s + "(",
                    open_count + 1,
                    close_count
                )
            if close_count < open_count:
                backtrack(
                    s + ")",
                    open_count,
                    close_count + 1
                )
        backtrack("", 0, 0)
        return result

# 56. Merge Intervals
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        result = []
        for start, end in intervals:
            if not result or start > result[-1][1]:
                result.append([start, end])
            else:
                result[-1][1] = max(result[-1][1], end)
        return result

# 146. LRU Cache
class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = OrderedDict()
    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]
    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.pop(key)
        self.cache[key] = value
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)

# 152. Maximum Product Subarray
class Solution:
    def maxProduct(self, nums):
        curr_max = nums[0]
        curr_min = nums[0]
        result = nums[0]
        for i in range(1, len(nums)):
            if nums[i] < 0:
                curr_max, curr_min = curr_min, curr_max
            curr_max = max(nums[i], curr_max * nums[i])
            curr_min = min(nums[i], curr_min * nums[i])
            result = max(result, curr_max)
        return result

# 198. House Robber
class Solution:
    def rob(self, nums: List[int]) -> int:
        prev2 = 0
        prev1 = 0
        for money in nums:
            current = max(prev1, prev2 + money)
            prev2 = prev1
            prev1 = current
        return prev1

# 200. Number of Islands
 class Solution:
    def numIslands(self, grid):
        if not grid:
            return 0
        rows = len(grid)
        cols = len(grid[0])
        islands = 0
        def dfs(r, c):
            if r < 0 or r >= rows or c < 0 or c >= cols:
                return
            if grid[r][c] != '1':
                return
            grid[r][c] = '0'
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1':
                    islands += 1
                    dfs(r, c)
        return islands

# 207. Course Schedule
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        from collections import deque
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        for course, prerequisite in prerequisites:
            graph[prerequisite].append(course)
            indegree[course] += 1
        queue = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)
        completed = 0
        while queue:
            course = queue.popleft()
            completed += 1
            for next_course in graph[course]:
                indegree[next_course] -= 1
                if indegree[next_course] == 0:
                    queue.append(next_course)
        return completed == numCourses

# 238. Product of Array Except Self
class Solution:
    def productExceptSelf(self, nums):
        n = len(nums)
        answer = [1] * n
        prefix = 1
        for i in range(n):
            answer[i] = prefix
            prefix *= nums[i]
        suffix = 1
        for i in range(n - 1, -1, -1):
            answer[i] *= suffix
            suffix *= nums[i]
        return answer

# 560. Subarray Sum Equals K
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

# 994. Rotting Oranges
class Solution:
    def orangesRotting(self, grid):
        rows = len(grid)
        cols = len(grid[0])
        queue = deque()
        fresh = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    queue.append((r, c))
                elif grid[r][c] == 1:
                    fresh += 1
        minutes = 0
        directions = [
            (1, 0),
            (-1, 0),
            (0, 1),
            (0, -1)
        ]
        while queue and fresh > 0:
            for _ in range(len(queue)):
                r, c = queue.popleft()
                for dr, dc in directions:
                    nr = r + dr
                    nc = c + dc
                    if (0 <= nr < rows and
                        0 <= nc < cols and
                        grid[nr][nc] == 1):
                        grid[nr][nc] = 2
                        fresh -= 1
                        queue.append((nr, nc))
            minutes += 1
        return minutes if fresh == 0 else -1

# 1202. Remove All Adjacent Duplicates in String II
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        for c in s:
            if stack and stack[-1][0] == c:
                stack[-1][1] += 1
                if stack[-1][1] == k:
                    stack.pop()
            else:
                stack.append([c, 1])
        return ''.join(c * count for c, count in stack)

# 1339. Maximum Product of Splitted Binary Tree
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        MOD = 10**9 + 7
        def get_sum(node):
            if not node:
                return 0
            return (
                node.val
                + get_sum(node.left)
                + get_sum(node.right)
            )
        total = get_sum(root)
        ans = 0
        def dfs(node):
            nonlocal ans
            if not node:
                return 0
            subtree_sum = (
                node.val
                + dfs(node.left)
                + dfs(node.right)
            )
            product = subtree_sum * (total - subtree_sum)
            ans = max(ans, product)
            return subtree_sum
        dfs(root)
        return ans % MOD

# 1386. Cinema Seat Allocation
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        reserved = {}
        for row, seat in reservedSeats:
            reserved.setdefault(row, set()).add(seat)
        result = (n - len(reserved)) * 2
        for seats in reserved.values():
            count = 0
            if not any(s in seats for s in [2, 3, 4, 5]):
                count += 1
            if not any(s in seats for s in [6, 7, 8, 9]):
                count += 1
            if count == 0 and not any(s in seats for s in [4, 5, 6, 7]):
                count = 1
            result += count
        return result

# 1461. Check If a String Contains All Binary Codes of Size K
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        if len(s) < (1 << k):
            return False
        see = {s[i:i+k] for i in range(len(s)-k+1)}
        return len(see) == (1 << k)

# 1944. Number of Visible People in a Queue
class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        n = len(heights)
        result = [0] * n
        stack = []
        for i in range(n - 1, -1, -1):
            while stack and heights[i] > stack[-1]:
                stack.pop()
                result[i] += 1
            if stack:
                result[i] += 1
            stack.append(heights[i])
        return result

# 2571. Minimum Operations to Reduce an Integer to 0
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

# 2615. Sum of Distances
class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        mp = defaultdict(list)
        for i, v in enumerate(nums):
            mp[v].append(i)
        for v in mp.values():
            k = len(v)
            prefix = [0] * (k + 1)
            for i in range(k):
                prefix[i + 1] = prefix[i] + v[i]
            for i in range(k):
                left = v[i] * i - prefix[i]
                right = (prefix[k] - prefix[i + 1]) - v[i] * (k - i - 1)
                res[v[i]] = left + right
        return res

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
