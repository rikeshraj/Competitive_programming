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


// 13. Roman to Integer
int value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;  // invalid character
    }
}
int romanToInt(char* s) {
    int total = 0;
    int prev = 0;
    for (int i = 0; s[i] != '\0'; i++) { } 
    int n = 0;
    while (s[n] != '\0') n++;
    for (int i = n - 1; i >= 0; i--) {
        int curr = value(s[i]);
        if (curr < prev) total -= curr;
        else total += curr;
        prev = curr;
    }
    return total;
}


// 14. Longest Common Prefix
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    static char prefix[1000];
    strcpy(prefix, strs[0]);
    for (int i = 1; i < strsSize; i++) {
        while (strncmp(strs[i], prefix, strlen(prefix)) != 0) {
            prefix[strlen(prefix) - 1] = '\0';  // shrink prefix
            if (prefix[0] == '\0') return "";
        }
    }
    return prefix;
}


// 20. Valid Parentheses
bool isValid(char* s) {
    int n = strlen(s);
    if (n%2 != 0) return false;
    char* stack = (char*)malloc(n * sizeof(char));;
    int top = -1;
    for (int i=0; i<n; i++) {
        char c = s[i];
        if (c=='(' || c=='{' || c=='[') {
            stack[++top] = c;
        } else {
            if (top==-1) return false;
            char last = stack[top--];
            if ((c==')' && last !='(') || (c=='}' && last !='{') || (c==']' && last!='[')) {
                return false;
            }
        }
    }
    return top==-1;
}


// 21. Merge Two Sorted Lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
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


// 26. Remove Duplicates from Sorted Array
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int k = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}


// 27. Remove Element
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}


// 28. Find the Index of the First Occurrence in a String
int strStr(char* haystack, char* needle) {
    if (needle[0] == '\0') return 0;
    for (int i = 0; haystack[i] != '\0'; i++) {
        int j = 0;
        while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
            j++;
        }
        if (needle[j] == '\0') return i;
    }
    return -1;
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


// 762. Prime Number of Set Bits in Binary Representation
int countSetBits(int n) {
    int count = 0;
    while(n>0) {
        n &= (n-1);
        count++;
    }
    return count;
}
bool isPrime(int n) {
    if(n<=1) return false; 
    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) return false; 
    }
    return true;
}
int countPrimeSetBits(int left, int right) {
    int primeBitsCount = 0;
    for(int i=left; i<=right; i++) {
        if(isPrime(countSetBits(i))) {
            primeBitsCount++;
        }
    }
    return primeBitsCount;
}


// 2078. Two Furthest Houses With Different Colors
int maxDistance(int* colors, int colorsSize) {
    int dist1 = 0, dist2 = 0;
    for (int j = colorsSize - 1; j >= 0; j--) {
        if (colors[j] != colors[0]) {
            dist1 = j;
            break;
        }
    }
    for (int i = 0; i < colorsSize; i++) {
        if (colors[i] != colors[colorsSize - 1]) {
            dist2 = (colorsSize - 1) - i;
            break;
        }
    }
    return dist1 > dist2 ? dist1 : dist2;
}


// 2833. Furthest Point From Origin
int furthestDistanceFromOrigin(char* moves) {
    int L = 0, R = 0, U = 0;
    for (int i = 0; moves[i]; i++) {
        if (moves[i] == 'L') L++;
        else if (moves[i] == 'R') R++;
        else U++;
    }
    int pos = R - L;
    if (pos >= 0)
        return pos + U;
    else
        return -pos + U;
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

