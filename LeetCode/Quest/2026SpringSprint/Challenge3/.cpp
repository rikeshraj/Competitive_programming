/*
Q1. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
*/
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

/*
Q2. Remove All Adjacent Duplicates in String II
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stack;
        for (char c : s) {
            if (!stack.empty() && stack.back().first == c) {
                stack.back().second++;
                if (stack.back().second == k) {
                    stack.pop_back();
                }
            }
            else {
                stack.push_back({c, 1});
            }
        }
        string result;
        for (auto& [c, count] : stack) {
            result.append(count, c);
        }
        return result;
    }
};

/*
Q3. Maximum Product of Splitted Binary Tree
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 10^9 + 7.
Note that you need to maximize the answer before taking the mod and not after taking it.
*/
class Solution {
public:
    using ll = long long;
    ll totalSum = 0;
    ll ans = 0;
    ll getSum(TreeNode* node) {
        if (!node)
            return 0;
        return node->val
             + getSum(node->left)
             + getSum(node->right);
    }
    ll dfs(TreeNode* node) {
        if (!node)
            return 0;
        ll subtreeSum =
            node->val
            + dfs(node->left)
            + dfs(node->right);
        ll product =
            subtreeSum * (totalSum - subtreeSum);
        ans = max(ans, product);
        return subtreeSum;
    }
    int maxProduct(TreeNode* root) {
        const ll MOD = 1000000007;
        totalSum = getSum(root);
        dfs(root);
        return ans % MOD;
    }
};
