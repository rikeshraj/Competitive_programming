// 1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) {
                int com = target-nums[i];
                if(map.count(com)) {
                    return {map[com], i};
                } 
            map[nums[i]] = i; 
        }
        return {};
    }
}; 


//9. PalindromeNumber
class Solution {
public:
    bool isPalindrome(int x) {
        long copy = x, rev = 0;
        while(x>0) {
            rev = rev*10 + x%10;
            x /= 10;
        }
        if(copy == rev) return true;
        return false;
    }
};

 
// 13. Roman to Integer
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000}
        };
        int total = 0;
        int prev = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int curr = roman[s[i]];
            if (curr < prev)
                total -= curr;
            else
                total += curr;
            prev = curr;
        }
        return total;
    }
};


// 14. Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < (int)strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {  // prefix not at start
                prefix.pop_back();
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};


// 20. Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c=='(' || c=='{' || c=='[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                if ((c==')') && top=='(' || (c=='}') && top=='{' || (c==']') && top=='[') {
                    st.pop();
                }else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};


// 21. Merge Two Sorted Lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = (list1) ? list1 : list2;
        return dummy.next;
    }
};


// 26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = 1; // index for next unique element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};


// 27. Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};


// 28. Find the Index of the First Occurrence in a String
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) return 0;
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;
        }
        return -1;
    }
};


// 35. Search Insert Position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};


// 58. Length of Last Word
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ')
            i--;
        int len = 0;
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }
        return len;
    }
};


// 66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};


//110. Balanced Binary Tree
class Solution {
private: 
    int checkHeight(TreeNode* node) {
        if(!node) {
            return 0;
        } 
        int leftHeight = checkHeight(node->left); 
        if(leftHeight == -1) return -1; 
        int rightHeight = checkHeight(node->right); 
        if(rightHeight == -1) return -1; 
        if(abs(leftHeight-rightHeight)>1) return -1; 
        return std::max(leftHeight, rightHeight)+1;
    }
public: 
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};


// 190. Reverse Bits
class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for(int i=0; i<32; ++i) {
            res <<= 1;
            res |= (n&1);
            n >>= 1;
        }
        return res;
    }
};
// OR
for(int i=0; i<32; ++i) {
    res = (res<<1) | (n&1);
    n >>= 1;
}


// 217. Contains Duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};

// 401. Binary Watch 
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res; 
        for(int h=0; h<12; h++) {
            for(int m=0; m<60; m++) {
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    res.push_back(to_string(h) + (m<10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return res;
    }
};


// 693. Binary Number with Alternating Bits
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int res = (unsigned int)n ^ ((unsigned int)n >> 1);
        return (res & (res+1)) == 0;
    }
};


// 696. Count Binary Substrings 
int countBinarySubstrings(char* s) {
    int previous_count = 0; 
    int current_count = 1; 
    int count = 0; 
    for(int i=1; i<strlen(s); i++) {
        if(s[i] == s[i-1]) {
            current_count++;
        }
        else {
            count += (previous_count < current_count) ? previous_count : current_count; 
            previous_count = current_count; 
            current_count = 1;
        }
    }
    count += (previous_count < current_count) ? previous_count : current_count; 
    return count; 
}


// 762. Prime Number of Set Bits in Binary Representation
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i=left; i<=right; i++) {
            int setBits = __builtin_popcount(i); 
            if(isPrime(setBits)) {
                count++;
            }
        }
        return count;
    }
private:
    bool isPrime(int n) {
        if(n<=1) return false;
        for(int i=2; i*i<=n; i++) {
            if(n%i == 0) return false;
        }
        return true;
    }
};


// 2078. Two Furthest Houses With Different Colors
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int dist1 = 0, dist2 = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (colors[j] != colors[0]) {
                dist1 = j;  // distance = j - 0
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1]) {
                dist2 = (n - 1) - i;
                break;
            }
        }
        return max(dist1, dist2);
    }
};


// 2833. Furthest Point From Origin
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, U = 0;
        for (char c : moves) {
            if (c == 'L') L++;
            else if (c == 'R') R++;
            else U++;
        }
        return abs(R - L) + U;
    }
};


// 3010. Divide an Array Into Subarrays With Minimum Cost I 
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int first = nums[0];
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int i=1; i<n; ++i) {
            if(nums[i]<min1) {
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i]<min2) {
                min2 = nums[i];
            }
        }
        return first+min1+min2;
    }
};


// 


// 

