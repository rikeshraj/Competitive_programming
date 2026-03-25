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
