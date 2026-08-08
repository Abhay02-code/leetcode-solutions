1class Solution {
2public:
3
4    int solve(vector<int>& slices, int start, int end, int k) {
5        int n = end - start + 1;
6
7        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
8
9        for (int i = 1; i <= n; i++) {
10            for (int j = 1; j <= k; j++) {
11
12                
13                int notTake = dp[i - 1][j];
14
15                
16                int take = slices[start + i - 1];
17
18                if (i >= 2)
19                    take += dp[i - 2][j - 1];
20                else if (j > 1)
21                    take = 0;
22
23                dp[i][j] = max(notTake, take);
24            }
25        }
26
27        return dp[n][k];
28    }
29
30    int maxSizeSlices(vector<int>& slices) {
31        int n = slices.size();
32        int k = n / 3;
33
34        int case1 = solve(slices, 0, n - 2, k);
35
36        
37        int case2 = solve(slices, 1, n - 1, k);
38
39        return max(case1, case2);
40    }
41};