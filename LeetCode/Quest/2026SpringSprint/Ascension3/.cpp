/*
Q1. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        for (auto& [num, count] : freq) {
            pq.push({count, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

/*
Q2. Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.
*/
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

/*
Q3. Minimum Edge Reversals So Every Node Is Reachable
There is a simple directed graph with n nodes labeled from 0 to n - 1. The graph would form a tree if its edges were bi-directional.
You are given an integer n and a 2D integer array edges, where edges[i] = [ui, vi] represents a directed edge going from node ui to node vi.
An edge reversal changes the direction of an edge, i.e., a directed edge going from node ui to node vi becomes a directed edge going from node vi to node ui.
For every node i in the range [0, n - 1], your task is to independently calculate the minimum number of edge reversals required so it is possible to reach any other node starting from node i through a sequence of directed edges.
Return an integer array answer, where answer[i] is the minimum number of edge reversals required so it is possible to reach any other node starting from node i through a sequence of directed edges.
*/
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
