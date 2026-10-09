1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int n = prices.size();
5        if (n == 0) return 0;
6
7        vector<int> hold(n), sold(n), cooldown(n);
8
9        hold[0] = -prices[0];
10        sold[0] = 0;
11        cooldown[0] = 0;
12
13        for (int i = 1; i < n; i++) {
14            hold[i] = max(hold[i - 1], cooldown[i - 1] - prices[i]);
15            sold[i] = hold[i - 1] + prices[i];
16            cooldown[i] = max(cooldown[i - 1], sold[i - 1]);
17        }
18
19        return max(sold[n - 1], cooldown[n - 1]);
20    }
21};