1class Solution {
2public:
3    int n;
4    vector<int> suffix;
5    vector<vector<int>> dp;
6
7    int solve(int i, int M) {
8        // No stones left
9        if (i >= n)
10            return 0;
11
12        // Can take all remaining stones
13        if (i + 2 * M >= n)
14            return suffix[i];
15
16        if (dp[i][M] != -1)
17            return dp[i][M];
18
19        int ans = 0;
20
21        // Take X piles, where 1 <= X <= 2*M
22        for (int X = 1; X <= 2 * M; X++) {
23
24            int opponent = solve(i + X, max(M, X));
25
26            // Total remaining stones - opponent's best
27            int current = suffix[i] - opponent;
28
29            ans = max(ans, current);
30        }
31
32        return dp[i][M] = ans;
33    }
34
35    int stoneGameII(vector<int>& piles) {
36        n = piles.size();
37
38        // suffix[i] = sum of piles[i ... n-1]
39        suffix.resize(n + 1, 0);
40
41        for (int i = n - 1; i >= 0; i--) {
42            suffix[i] = suffix[i + 1] + piles[i];
43        }
44
45        dp.assign(n, vector<int>(n + 1, -1));
46
47        return solve(0, 1);
48    }
49};