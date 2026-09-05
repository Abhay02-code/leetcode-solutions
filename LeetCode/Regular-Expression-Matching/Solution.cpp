1class Solution {
2public:
3    bool isMatch(string s, string p) {
4        int n = s.size();
5        int m = p.size();
6
7        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
8
9        
10        dp[0][0] = 1;
11
12        
13        for(int j = 2; j <= m; j++) {
14            if(p[j - 1] == '*') {
15                dp[0][j] = dp[0][j - 2];
16            }
17        }
18
19        for(int i = 1; i <= n; i++) {
20            for(int j = 1; j <= m; j++) {
21
22                
23                if(p[j - 1] == s[i - 1] || p[j - 1] == '.') {
24                    dp[i][j] = dp[i - 1][j - 1];
25                }
26
27                
28                else if(p[j - 1] == '*') {
29
30                    
31                    dp[i][j] = dp[i][j - 2];
32
33                    if(p[j - 2] == s[i - 1] || p[j - 2] == '.') {
34                        dp[i][j] = dp[i][j] || dp[i - 1][j];
35                    }
36                }
37            }
38        }
39
40        return dp[n][m];
41    }
42};