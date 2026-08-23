// 2. Add Two Numbers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            if (l1 != nullptr) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                carry += l2->val; 
                l2 = l2->next; 
            } 
            current->next = new ListNode(carry % 10); 
            carry /= 10; 
            current = current->next; 
        }
        return dummy.next;
    }
}; 

// 22. Generate Parentheses
class Solution {
public:
    vector<string> result;
    void backtrack(string& s, int open, int close, int n) {
        if (s.size() == 2 * n) {
            result.push_back(s);
            return;
        }
        if (open < n) {
            s.push_back('(');
            backtrack(s, open + 1, close, n);
            s.pop_back();
        }
        if (close < open) {
            s.push_back(')');
            backtrack(s, open, close + 1, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        backtrack(s, 0, 0, n);
        return result;
    }
};

// 49. Group Anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& [key, words] : groups) {
            result.push_back(words);
        }
        return result;
    }
};

// 56. Merge Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            if (result.empty() || start > result.back()[1]) {
                result.push_back({start, end});
            }
            else {
                result.back()[1] =
                    max(result.back()[1], end);
            }
        }
        return result;
    }
};

// 146. LRU Cache
class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        auto it = mp[key];
        int value = it->second;
        cache.splice(cache.begin(), cache, it);
        return value;        
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
            return;
        }
        cache.push_front({key, value});
        mp[key] = cache.begin();
        if (cache.size() > capacity) {
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }
    }
};

// 152. Maximum Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }
            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);
            result = max(result, currMax);
        }
        return result;
    }
};

// 198. House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;
        for (int money : nums) {
            int current = max(prev1, prev2 + money);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

// 200. Number of Islands
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (r < 0 || r >= rows ||
            c < 0 || c >= cols ||
            grid[r][c] != '1') {
            return;
        }
        grid[r][c] = '0';
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }
        return islands;
    }
};

// 207. Course Schedule
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];
            graph[prerequisite].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int completed = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            completed++;
            for (int nextCourse : graph[course]) {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        return completed == numCourses;
    }
};

// 238. Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;
    }
};

// 560. Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int prefixSum = 0;
        int count = 0;
        for (int num : nums) {
            prefixSum += num;
            if (freq.find(prefixSum - k) != freq.end()) {
                count += freq[prefixSum - k];
            }
            freq[prefixSum]++;
        }
        return count;
    }
};

// 994. Rotting Oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
                else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }
        int minutes = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr >= 0 && nr < rows &&
                        nc >= 0 && nc < cols &&
                        grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};

// 1202. Remove All Adjacent Duplicates in String II
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stack;
        for (char c : s) {
            if (!stack.empty() && stack.back().first == c) {
                stack.back().second++;
                if (stack.back().second == k) {
                    stack.pop_back();
                }
            }
            else {
                stack.push_back({c, 1});
            }
        }
        string result;
        for (auto& [c, count] : stack) {
            result.append(count, c);
        }
        return result;
    }
};

// 1249. Minimum Remove to Make Valid Parentheses
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(i);
            }
            else if (s[i] == ')') {
                if (!stack.empty()) {
                    stack.pop_back();
                }
                else {
                    s[i] = '*';
                }
            }
        }
        while (!stack.empty()) {
            s[stack.back()] = '*';
            stack.pop_back();
        }
        string result;
        for (char ch : s) {
            if (ch != '*') {
                result += ch;
            }
        }
        return result;
    }
};

// 1339. Maximum Product of Splitted Binary Tree
class Solution {
public:
    using ll = long long;
    ll totalSum = 0;
    ll ans = 0;
    ll getSum(TreeNode* node) {
        if (!node)
            return 0;
        return node->val
             + getSum(node->left)
             + getSum(node->right);
    }
    ll dfs(TreeNode* node) {
        if (!node)
            return 0;
        ll subtreeSum =
            node->val
            + dfs(node->left)
            + dfs(node->right);
        ll product =
            subtreeSum * (totalSum - subtreeSum);
        ans = max(ans, product);
        return subtreeSum;
    }
    int maxProduct(TreeNode* root) {
        const ll MOD = 1000000007;
        totalSum = getSum(root);
        dfs(root);
        return ans % MOD;
    }
};

// 1386. Cinema Seat Allocation
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;
        for (auto& seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }
        int result = (n - reserved.size()) * 2;
        for (auto& [row, seats] : reserved) {
            bool left = true;
            bool middle = true;
            bool right = true;
            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }
            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                    break;
                }
            }
            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }
            if (left && right) {
                result += 2;
            }
            else if (left || middle || right) {
                result += 1;
            }
        }
        return result;
    }
};

// 1461. Check If a String Contains All Binary Codes of Size K
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (1 << k)) return false; 
        unordered_set<string> see;
        for (int i=0; i<=(int)s.size()-k; i++) {
            see.insert(s.substr(i, k));
            if(see.size() == (1 << k)) return true;
        }
        return see.size() == (1 << k);
    }
};

// 1944. Number of Visible People in a Queue
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] > st.top()) {
                st.pop();
                result[i]++;
            }
            if (!st.empty()) {
                result[i]++;
            }
            st.push(heights[i]);
        }
        return result;
    }
};

// 2571. Minimum Operations to Reduce an Integer to 0
class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while (n > 0) {
            if ((n & 3) == 3) {
                n += 1;
                ans++;
            }
            else if (n & 1) {
                n -= 1;
                ans++;
            }
            else {
                n >>= 1;
            }
        }
        return ans;
    }
};

// 2615. Sum of Distances
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto &p : mp) {
            auto &v = p.second;
            int k = v.size();
            vector<long long> prefix(k + 1, 0);
            for (int i = 0; i < k; i++) {
                prefix[i + 1] = prefix[i] + v[i];
            }
            for (int i = 0; i < k; i++) {
                long long left = (long long)v[i] * i - prefix[i];
                long long right = (prefix[k] - prefix[i + 1]) - (long long)v[i] * (k - i - 1);
                res[v[i]] = left + right;
            }
        }
        return res;
    }
};

// 3546. Equal Sum Grid Partition I
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long totalSum = 0; 
        int m = grid.size();
        int n = grid[0].size();
        for (const auto& row : grid) {
            for (int val : row) {
                totalSum += val;
            }
        }
        if (totalSum%2 != 0) return false; 
        long target = totalSum/2;
        long currentSum = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                currentSum += grid[i][j];
            }
            if (currentSum == target) return true;
        }
        currentSum = 0;
        for (int j=0; j<n; j++) {
            for (int i=0; i<m; i++) {
                currentSum += grid[i][j];
            }
            if (currentSum == target) return true; 
        }
        return false; 
    }
};

// 3713. Longest Balanced Substring I
class Solution {
public:
    int longestBalanced(string s) {
        int n = (int)s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int counts[26] = {0};
            int distinctChar = 0;
            for (int j = i; j < n; j++) {
                int charId = s[j] - 'a';
                if (counts[charId] == 0) {
                    distinctChar++;
                }
                counts[charId]++;
                int currentLen = j - i + 1;
                if (currentLen % distinctChar == 0) {
                    int targetCount = currentLen / distinctChar;
                    bool isBalanced = true;
                    for (int k = 0; k < 26; k++) {
                        if (counts[k] > 0 && counts[k] != targetCount) {
                            isBalanced = false;
                            break;
                        }
                    }
                    if (isBalanced) {
                        maxLen = max(maxLen, currentLen);
                    }
                }
            }
        }
        return maxLen;
    }
};
