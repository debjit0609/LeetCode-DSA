int numDistinct(char* s, char* t) {
    int s_len = 0, t_len = 0;
    while (s[s_len]) s_len++;
    while (t[t_len]) t_len++;
    
    unsigned int dp[1005] = {0};
    dp[0] = 1;
    
    for (int i = 1; i <= s_len; i++) {
        for (int j = t_len; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }
    
    return dp[t_len];
}