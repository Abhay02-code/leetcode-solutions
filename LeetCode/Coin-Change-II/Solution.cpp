1class Solution {
2public:
3    int change(int amount, vector<int>& coins) {
4        int n = coins.size();
5
6        if (n == 0)
7            return amount == 0 ? 1 : 0;
8
9        vector<long long> prev(amount + 1, 0);
10
11        for (int target = 0; target <= amount; target++) {
12            if (target % coins[0] == 0)
13                prev[target] = 1;
14        }
15
16        for (int idx = 1; idx < n; idx++) {
17            vector<long long> cur(amount + 1, 0);
18
19            for (int target = 0; target <= amount; target++) {
20                int notTake = prev[target];
21
22                long long take = 0;
23                if (coins[idx] <= target)
24                    take = cur[target - coins[idx]];
25
26                cur[target] = take + notTake;
27            }
28
29            prev = cur;
30        }
31
32        return prev[amount];
33    }
34};