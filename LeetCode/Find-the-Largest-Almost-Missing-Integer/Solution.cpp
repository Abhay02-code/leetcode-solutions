1class Solution {
2public:
3    int largestInteger(vector<int>& nums, int k) {
4        int n = nums.size();
5        unordered_map<int, int> freq;
6
7        for (int x : nums)
8            freq[x]++;
9
10        int ans = -1;
11
12        if (k == 1) {
13            for (auto [x, f] : freq) {
14                if (f == 1)
15                    ans = max(ans, x);
16            }
17        }
18        else if (k == n) {
19            return *max_element(nums.begin(), nums.end());
20        }
21        else {
22            if (freq[nums[0]] == 1)
23                ans = max(ans, nums[0]);
24
25            if (freq[nums[n - 1]] == 1)
26                ans = max(ans, nums[n - 1]);
27        }
28
29        return ans;
30    }
31};