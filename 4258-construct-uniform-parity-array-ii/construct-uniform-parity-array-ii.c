#include <stdbool.h>
#include <limits.h>

bool uniformArray(int* nums1, int nums1Size) {
    int mn = INT_MAX;
    
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] % 2 != 0) {
            if (nums1[i] < mn) {
                mn = nums1[i];
            }
        }
    }
    
    if (mn == INT_MAX) {
        return true;
    }
    
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] % 2 == 0 && nums1[i] < mn) {
            return false;
        }
    }
    
    return true;
}