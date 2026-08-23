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
