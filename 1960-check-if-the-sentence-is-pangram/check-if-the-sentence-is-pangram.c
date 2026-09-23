bool checkIfPangram(char * sentence) {
    int arr[26] = {0};
    int i = 0;
    
    while (sentence[i] != '\0') {
        arr[sentence[i] - 'a'] = 1;
        i++;
    }
    
    for (i = 0; i < 26; i++) {
        if (arr[i] == 0) {
            return false;
        }
    }
    
    return true;
}