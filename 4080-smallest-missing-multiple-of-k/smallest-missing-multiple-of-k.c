int missingMultiple(int* nums, int numsSize, int k) {
    int x = k;
    int temp = 1;
    while(temp) {
        temp = 0;
        for(int i = 0; i < numsSize; i++) {
            if(nums[i] == x) {
                temp = 1;
                x += k;
                break;
            }
        }
    }
    return x;
}