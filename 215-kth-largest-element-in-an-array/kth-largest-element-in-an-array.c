#include <stdio.h>
#include <stdlib.h>
int findKthLargest(int* nums, int numsSize, int k) {

    int n = numsSize;
    
    if (n == 0) {
        return 0;
    }

    int min = nums[0];
    int max = nums[0];
    
    for (int i = 1; i < n; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    int range = max - min + 1;
    int* count = (int*)calloc(range, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        count[nums[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            nums[index++] = i + min;
            count[i]--;
        }
    }

    free(count);

    return nums[numsSize-k];
}