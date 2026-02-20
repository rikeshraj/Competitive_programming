// 1. Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* res = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    for(int i=0; i<numsSize; i++) {
        for(int j=i+1; j<numsSize; j++) {
            if(nums[i]+nums[j] == target) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return NULL;
}


// 9. Palindrome Number
bool isPalindrome(int x) {
    long copy = x;
    long rev = 0;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return copy == rev;
}


// 110. Balanced Binary Tree
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
static int max(int a, int b) {
    return (a > b) ? a : b;
}
static int abs_int(int x) {
    return (x < 0) ? -x : x;
}
static int checkHeight(struct TreeNode* node) {
    if (node == NULL) return 0;
    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1) return -1;
    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1) return -1;
    if (abs_int(leftHeight - rightHeight) > 1) return -1;
    return 1 + max(leftHeight, rightHeight);
}
bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;
}


// 190. Reverse Bits
int reverseBits(int n) {
    int res = 0;
    for(int i=0; i<32; ++i) {
        res <<= 1;
        res |= (n&1);
        n >>= 1;
    }
    return res;
}
// OR 
for(int i=0; i<32; ++i) {
    res = (res<<1) | (n&1);
    n >>= 1;
}


// 217. Contains Duplicate
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) return false;
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    return false;
}

// 401. Binary Watch 
int countSetBits(int n) {
    int count = 0; 
    while(n>0) {
        count += (n&1); 
        n >>= 1; 
    }
    return count; 
}
char** readBinaryWatch(int turnedOn, int* return Size) {
    char** res = (char**)malloc(720*sizeof(char*)); 
    int count = 0; 
    for(int h=0; h<12; h++) {
        for(int m=0; m<60; m++) {
            if(countSetBits(h) + countSetBits(m) == turnedOn) {
                res[count] = (char*)malloc(6*sizeof(char)); 
                sprintf(res[count], "%d:%02d", h, m); 
                count++;
            }
        }
    }
    *returnSize = count; 
    return res;
}


// 693. Binary Number with Alternating Bits
bool hasAlternatingBits(int n) {
    unsigned int res = (unsigned int)n ^ ((unsigned int)n >> 1);
    return (res & (res+1)) == 0;
}


// 696. Count Binary Substrings 
class Solution {
public:
    int countBinarySubstrings(string s) {
        int previous_count = 0; 
        int current_count = 1; 
        int count = 0; 
        for(int i=1; i<s.length(); i++) {
            if(s[i] == s[i-1]) {
                current_count++;
            }
            else {
                count += min(previous_count, current_count); 
                previous_count = current_count; 
                current_count = 1;
            }
        }
        count += min(previous_count, current_count); 
        return count; 
    }
};


// 761. Special Binary String
int compare(const void *a, const void *b) {
    return strcmp(*(char **)b, *(char **)a);
} 
char* makeLargestSpecial(char* s) {
    int len = strlen(s); 
    if(len == 0) return strdup("");
    int count = 0, i = 0, num_spec = 0; 
    char** spec = malloc(len * sizeof(char*));
    for(int j=0; j<len; j++) {
        count += (s[j] == '1') ? 1 : -1;
        if(count == 0) {
            int sub_len = j-i-1;
            char* inner = malloc(sub_len + 1);
            strncpy(inner, s+i+1, sub_len);
            inner[sub_len] = '\0';
            char* processed_inner = makeLargestSpecial(inner);
            spec[num_spec] = malloc(strlen(processed_inner) + 3);
            sprintf(spec[num_spec], "1%s0", processed_inner);
            num_spec++;
            i = j+1; 
            free(inner);
            free(processed_inner);
        }
    }
    qsort(spec, num_spec, sizeof(char*), compare);
    char* result = calloc(len+1, 1);
    for(int k=0; k<num_spec; k++) {
        strcat(result, spec[k]);
        free(spec[k]);
    }
    free(spec);
    return result; 
}


// 3010. Divide an Array Into Subarrays With Minimum Cost I 
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int minimumCost(int* nums, int numsSize) {
    int firstCost = nums[0];
    qsort(nums + 1, numsSize - 1, sizeof(int), compare);
    int secondCost = nums[1];
    int thirdCost = nums[2];
    return firstCost + secondCost + thirdCost;
}


// 


// 

