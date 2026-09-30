1class Solution {
2public:
3    bool isMatch(string s, string p) {
4        int n = s.size();
5        int m = p.size();
6        vector<vector<bool>>dp(n+1, vector<bool>(m+1,false));
7        dp[0][0] = true;
8        for(int i = 1; i <= m; i++){
9            if(p[i-1] == '*'){
10                dp[0][i] = dp[0][i-1];
11            }
12
13        }
14        for(int i = 1; i <= n; i++){
15            for(int j = 1; j <= m; j++){
16                 if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
17                    dp[i][j] = dp[i - 1][j - 1];
18                }
19                else if (p[j - 1] == '*') {
20                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
21                }
22            }
23        }
24        return dp[n][m];
25
26        
27
28    }
29};