/*
Q1. Minimum Remove to Make Valid Parentheses
Given a string s of '(' , ')' and lowercase English characters.
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:
It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
*/
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

/*
Q2.Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/
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

/*
Q3. Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
*/
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
