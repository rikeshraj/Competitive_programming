/* 
Q1. Maximum Product Subarray
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
Note that the product of an array with a single element is the value of that element.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }
            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);
            result = max(result, currMax);
        }
        return result;
    }
};

/*
Q2. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;
    }
};

/*
Q3. Cinema Seat Allocation
A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.
You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.
A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:
seats 2, 3, 4, 5
seats 4, 5, 6, 7
seats 6, 7, 8, 9
A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.
Return an integer denoting the maximum number of four-person groups that can be assigned.
*/
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;
        for (auto& seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }
        int result = (n - reserved.size()) * 2;
        for (auto& [row, seats] : reserved) {
            bool left = true;
            bool middle = true;
            bool right = true;
            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }
            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                    break;
                }
            }
            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }
            if (left && right) {
                result += 2;
            }
            else if (left || middle || right) {
                result += 1;
            }
        }
        return result;
    }
};
