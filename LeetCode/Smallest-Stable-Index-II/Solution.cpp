1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4
5      
6        vector<int> velqanidor = nums;
7
8        int n = nums.size();
9
10       
11        for (int i = n - 2; i >= 0; i--) {
12            nums[i] = min(nums[i], nums[i + 1]);
13        }
14
15        int prefixMax = 0;
16
17        for (int i = 0; i < n; i++) {
18
19            prefixMax = max(prefixMax, velqanidor[i]);
20
21            if (prefixMax - nums[i] <= k) {
22                return i;
23            }
24        }
25
26        return -1;
27    }
28};