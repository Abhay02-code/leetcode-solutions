1class Solution {
2public:
3    vector<int> dp;
4
5    bool solve(int n) {
6        if(n == 0)
7            return false;
8
9        if(dp[n] != -1)
10            return dp[n];
11
12        for(int i = 1; i*i <= n; i++) {
13            if(!solve(n - i*i))
14                return dp[n] = true;
15        }
16
17        return dp[n] = false;
18    }
19
20    bool winnerSquareGame(int n) {
21        dp.resize(n + 1, -1);
22        return solve(n);
23    }
24};