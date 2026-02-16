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

