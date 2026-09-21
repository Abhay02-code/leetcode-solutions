1class Solution {
2public:
3    vector<long long> resultArray(vector<int>& nums, int k) {
4        vector<long long> ans(k, 0);
5        vector<long long> dp(k, 0);
6
7        for (int num : nums) {
8            vector<long long> newdp(k, 0);
9
10            newdp[num % k]++;
11
12            for (int r = 0; r < k; r++) {
13                newdp[(r * (num % k)) % k] += dp[r];
14            }
15
16            dp = newdp;
17
18            for (int r = 0; r < k; r++) {
19                ans[r] += dp[r];
20            }
21        }
22
23        return ans;
24    }
25};