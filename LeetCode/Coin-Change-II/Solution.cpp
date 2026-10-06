1class Solution {
2public:
3    int change(int amount, vector<int>& coins) {
4        vector<unsigned int> dp(amount + 1, 0);
5        dp[0] = 1;
6
7        for (int coin : coins) {
8            for (int j = coin; j <= amount; j++) {
9                dp[j] += dp[j - coin];
10            }
11        }
12
13        return (int)dp[amount];
14    }
15};