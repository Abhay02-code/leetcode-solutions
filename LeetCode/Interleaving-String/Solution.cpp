1class Solution {
2public:
3    bool isInterleave(string s1, string s2, string s3) {
4        int m = s1.size();
5        int n = s2.size();
6
7        if (m + n != s3.size()) return false;
8
9        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
10
11        dp[0][0] = true;
12
13        for (int i = 1; i <= m; i++) {
14            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
15        }
16
17        for (int j = 1; j <= n; j++) {
18            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
19        }
20
21        for (int i = 1; i <= m; i++) {
22            for (int j = 1; j <= n; j++) {
23                dp[i][j] =
24                    (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
25                    (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
26            }
27        }
28
29        return dp[m][n];
30    }
31};