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


//3010. Divide an Array Into Subarrays With Minimum Cost I 
lass Solution {
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


