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

