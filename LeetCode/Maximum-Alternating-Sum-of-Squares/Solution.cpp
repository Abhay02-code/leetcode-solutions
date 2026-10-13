1
2class Solution {
3public:
4    long long maxAlternatingSum(vector<int>& nums) {
5        vector<long long> sq;
6
7        for (int x : nums) {
8            sq.push_back(1LL * x * x);
9        }
10
11        sort(sq.begin(), sq.end());
12
13        long long ans = 0;
14        int n = sq.size();
15
16        for (int i = 0; i < n; i++) {
17            if (i < n / 2) {
18                ans -= sq[i];
19            } else {
20                ans += sq[i];
21            }
22        }
23
24        return ans;
25    }
26};
27