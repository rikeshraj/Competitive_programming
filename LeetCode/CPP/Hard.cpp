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
