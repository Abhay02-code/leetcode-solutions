1class Solution {
2public:
3    int distinctSubseqII(string s) {
4
5        const int MOD = 1e9 + 7;
6
7        vector<long long> dp(26, 0);
8
9        for (char c : s) {
10
11            int index = c - 'a';
12
13            long long total = 0;
14
15            // Count all existing subsequences
16            for (int i = 0; i < 26; i++) {
17                total = (total + dp[i]) % MOD;
18            }
19
20            // Replace subsequences ending with current character
21            dp[index] = (total + 1) % MOD;
22        }
23
24        long long ans = 0;
25
26        for (int i = 0; i < 26; i++) {
27            ans = (ans + dp[i]) % MOD;
28        }
29
30        return ans;
31    }
32};