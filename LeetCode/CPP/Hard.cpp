// 4. Median of Two Sorted Arrays
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        int half = (m + n + 1) / 2;
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = half - i;
            int Aleft =
                (i > 0) ? nums1[i - 1] : INT_MIN;
            int Aright =
                (i < m) ? nums1[i] : INT_MAX;
            int Bleft =
                (j > 0) ? nums2[j - 1] : INT_MIN;
            int Bright =
                (j < n) ? nums2[j] : INT_MAX;
            if (Aleft <= Bright &&
                Bleft <= Aright) {
                if ((m + n) % 2 == 1) {
                    return max(Aleft, Bleft);
                }
                return (
                    max(Aleft, Bleft) +
                    min(Aright, Bright)
                ) / 2.0;
            }
            else if (Aleft > Bright) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }
        return 0.0;
    }
};

// 23. Merge k Sorted Lists
class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > pq;
        for (ListNode* node : lists) {
            if (node) {
                pq.push(node);
            }
        }
        ListNode dummy(0);
        ListNode* current = &dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            current->next = node;
            current = current->next;
            if (node->next) {
                pq.push(node->next);
            }
        }
        return dummy.next;
    }
};

// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {
                    water += leftMax - height[left];
                }
                left++;
            }
            else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                }
                else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};

// 85. Maximal Rectangle
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        for (auto& row : matrix) {
            for (int j = 0; j < cols; j++) {
                if (row[j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            stack<int> st;
            st.push(-1);
            for (int i = 0; i <= cols; i++) {
                int current = (i == cols) ? 0 : heights[i];
                while (st.top() != -1 &&
                       heights[st.top()] > current) {
                    int h = heights[st.top()];
                    st.pop();
                    int width = i - st.top() - 1;
                    maxArea = max(maxArea, h * width);
                }
                st.push(i);
            }
        }
        return maxArea;
    }
};

// 239. Sliding Window Maximum
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() &&
                   nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

// 761. Special Binary String
class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0; 
        int i = 0; 
        vector<string> res; 
        for(int j=0; j<s.length(); j++) {
            if(s[j] == '1') {
                count ++; 
            } else {
                count--;
            }
            if(count == 0) {
                res.push_back("1" + makeLargestSpecial(s.substr(i+1, j-i-1)) + "0");
                i = j+1;
            }
        }
        sort(res.begin(), res.end(), greater<string>());
        string finalResult = "";
        for(const string str : res) {
            finalResult += str;
        }
        return finalResult; 
    }
};

// 2858. Minimum Edge Reversals So Every Node Is Reachable
class Solution {
public:
    vector<vector<pair<int, int>>> graph;
    vector<int> ans;
    int dfs(int node, int parent) {
        int total = 0;
        for (auto [nei, cost] : graph[node]) {
            if (nei == parent)
                continue;
            total += cost;
            total += dfs(nei, node);
        }
        return total;
    }
    void reroot(int node, int parent) {
        for (auto [nei, cost] : graph[node]) {
            if (nei == parent)
                continue;
            if (cost == 0) {
                ans[nei] = ans[node] + 1;
            }
            else {
                ans[nei] = ans[node] - 1;
            }
            reroot(nei, node);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        ans.resize(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back({v, 0});
            graph[v].push_back({u, 1});
        }
        ans[0] = dfs(0, -1);
        reroot(0, -1);
        return ans;
    }
};
