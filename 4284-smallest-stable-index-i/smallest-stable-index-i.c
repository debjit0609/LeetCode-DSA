#include <stdlib.h>

int firstStableIndex(int* nums, int numsSize, int k) {
    if (numsSize == 0) return -1;

    int* pref_max = (int*)malloc(numsSize * sizeof(int));
    int* suff_min = (int*)malloc(numsSize * sizeof(int));
    
    pref_max[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        pref_max[i] = pref_max[i - 1] > nums[i] ? pref_max[i - 1] : nums[i];
    }
    
    suff_min[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        suff_min[i] = suff_min[i + 1] < nums[i] ? suff_min[i + 1] : nums[i];
    }
    
    int ans = -1;
    for (int i = 0; i < numsSize; i++) {
        if (pref_max[i] - suff_min[i] <= k) {
            ans = i;
            break;
        }
    }
    
    free(pref_max);
    free(suff_min);
    
    return ans;
}