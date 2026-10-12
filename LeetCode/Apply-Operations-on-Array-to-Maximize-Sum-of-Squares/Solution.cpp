1
2class Solution {
3public:
4    int maxSum(vector<int>& nums, int k) {
5        const int MOD = 1e9 + 7;
6        long long ans = 0;
7        int n = nums.size();
8
9        vector<int> bits(31, 0);
10
11        // Count set bits at each position
12        for (int num : nums) {
13            for (int i = 0; i < 31; i++) {
14                if (num & (1 << i)) {
15                    bits[i]++;
16                }
17            }
18        }
19
20        // Construct k numbers with maximum set bits
21        for (int j = 0; j < k; j++) {
22            long long x = 0;
23
24            for (int i = 30; i >= 0; i--) {
25                if (bits[i] > 0) {
26                    x |= (1LL << i);
27                    bits[i]--;
28                }
29            }
30
31            ans = (ans + x * x) % MOD;
32        }
33
34        return ans;
35    }
36};
37