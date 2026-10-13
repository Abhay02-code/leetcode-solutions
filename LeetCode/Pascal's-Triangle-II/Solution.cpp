1
2class Solution {
3public:
4    vector<int> getRow(int rowIndex) {
5        vector<int> dp(rowIndex + 1, 1);
6
7        for (int i = 2; i <= rowIndex; i++) {
8            for (int j = i - 1; j > 0; j--) {
9                dp[j] = dp[j] + dp[j - 1];
10            }
11        }
12
13        return dp;
14    }
15};
16