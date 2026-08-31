double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int* arr = (int*)malloc(totalSize * sizeof(int));
    
    if (nums1Size > 0 && nums2Size > 0 && nums1[nums1Size - 1] <= nums2[0]) {
        for (int i = 0; i < nums1Size; i++) {
            arr[i] = nums1[i];
        }
        int idx = nums1Size;
        for (int i = 0; i < nums2Size; i++) {
            arr[idx++] = nums2[i];
        }
    } 
    else if (nums1Size > 0 && nums2Size > 0 && nums2[nums2Size - 1] <= nums1[0]) {
        for (int i = 0; i < nums2Size; i++) {
            arr[i] = nums2[i];
        }
        int idx = nums2Size;
        for (int i = 0; i < nums1Size; i++) {
            arr[idx++] = nums1[i];
        }
    } 
    else {
        int i = 0, j = 0, k = 0;
        while (i < nums1Size && j < nums2Size) {
            if (nums1[i] <= nums2[j]) {
                arr[k++] = nums1[i++];
            } else {
                arr[k++] = nums2[j++];
            }
        }
        while (i < nums1Size) {
            arr[k++] = nums1[i++];
        }
        while (j < nums2Size) {
            arr[k++] = nums2[j++];
        }
    }
    
    double median;
    if (totalSize % 2 == 0) {
        median = (arr[totalSize / 2 - 1] + arr[totalSize / 2]) / 2.0;
    } else {
        median = arr[totalSize / 2];
    }
    
    free(arr);
    return median;
}