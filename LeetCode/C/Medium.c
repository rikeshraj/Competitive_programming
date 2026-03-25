// 2. Add Two Numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    struct ListNode* current = dummyHead; 
    int carry = 0; 
    while(l1 != NULL ||l2 != NULL || carry != 0) {
        int val1 = l1 != NULL ? l1->val : 0;
        int val2 = l2 != NULL ? l2->val : 0;
        int total = val1 + val2 + carry; 
        carry = total/10;
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = total%10; 
        current->next->next = NULL; 
        current = current->next; 
        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
    }
    return dummyHead->next;
}


// 1461. Check If a String Contains All Binary Codes of Size K
bool hasAllCodes(char* s, int k) {
    int n = strlen(s);
    int numCodes = 1 << k;
    if(n < numCodes+k-1) return false;
    bool* see = (bool*)calloc(numCodes, sizeof(bool));
    int current = 0;
    int count = 0;
    int mask = numCodes-1;
    for(int i=0; i<n; i++) {
        current = ((current << 1) & mask) | (s[i]-'0');
        if(i >= k-1) {
            if(!see[current]) {
                see[current] = true;
                count++;
            }
        }
        if(count == numCodes) {
            free(see);
            return true;
        }
    }
    free(see);
    return false;
}


// 3546. Equal Sum Grid Partition I
bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    long totalSum = 0;
    int m = gridSize; 
    int n = gridColSize[0];
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            totalSum += grid[i][j];
        }
    }
    if (totalSum%2 != 0) return false;
    long target = totalSum/2;
    long currentSum = 0; 
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            currentSum += grid[i][j];
        }
        if (currentSum == target) return true;
    }
    currentSum = 0;
    for (int j=0; j<n; j++) {
        for (int i=0; i<m; i++) {
            currentSum += grid[i][j];
        }
        if (currentSum == target) return true;
    }
    return false; 
}


// 3713. Longest Balanced Substring I
static int max_int(int a, int b) {
    return (a > b) ? a : b;
}
int longestBalanced(char* s) {
    int n = (int)strlen(s);
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int counts[26];
        memset(counts, 0, sizeof(counts));
        int distinctChar = 0;
        for (int j = i; j < n; j++) {
            int charId = s[j] - 'a';
            if (counts[charId] == 0) {
                distinctChar++;
            }
            counts[charId]++;
            int currentLen = j - i + 1;
            if (currentLen % distinctChar == 0) {
                int targetCount = currentLen / distinctChar;
                int isBalanced = 1;
                for (int k = 0; k < 26; k++) {
                    if (counts[k] > 0 && counts[k] != targetCount) {
                        isBalanced = 0;
                        break;
                    }
                }
                if (isBalanced) {
                    maxLen = max_int(maxLen, currentLen);
                }
            }
        }
    }
    return maxLen;
}
