/*
Q1. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
*/
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

/*
Q2. Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
*/
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

/*
Q3. Minimum Operations to Reduce an Integer to 0
You are given a positive integer n, you can do the following operation any number of times:
Add or subtract a power of 2 from n.
Return the minimum number of operations to make n equal to 0.
A number x is power of 2 if x == 2i where i >= 0.
*/
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
