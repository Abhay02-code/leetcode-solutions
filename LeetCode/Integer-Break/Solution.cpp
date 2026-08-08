1class Solution {
2public:
3    int integerBreak(int n) {
4        vector<int>dp(n+1, 0);
5
6        dp[2] = 1;
7
8        for(int i = 3; i <= n; i++){
9            for(int j = 1; j < i; j++){
10                dp[i] = max(
11                    dp[i],
12                    max(
13                        j * (i-j),
14                        j * dp[i-j]
15                    )
16                );
17            }
18        }
19        return dp[n];
20        
21    }
22};