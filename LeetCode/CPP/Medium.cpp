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
