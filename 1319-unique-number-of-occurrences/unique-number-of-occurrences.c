bool uniqueOccurrences(int* arr, int arrSize) {
    int counts[2001] = {0};
    int seen[1001] = {0};
    
    for (int i = 0; i < arrSize; i++) {
        counts[arr[i] + 1000]++;
    }
    
    for (int i = 0; i < 2001; i++) {
        if (counts[i] > 0) {
            if (seen[counts[i]] == 1) {
                return false;
            }
            seen[counts[i]] = 1;
        }
    }
    
    return true;
}