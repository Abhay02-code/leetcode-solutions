1class Solution {
2public:
3    int minSumOfLengths(vector<int>& arr, int target) {
4        int n = arr.size();
5        const int INF = 1e9;
6
7        // best[i] = minimum length of a valid subarray
8        // ending at or before index i
9        vector<int> best(n, INF);
10
11        int left = 0;
12        int sum = 0;
13        int ans = INF;
14
15        for (int right = 0; right < n; right++) {
16            sum += arr[right];
17
18            while (sum > target) {
19                sum -= arr[left];
20                left++;
21            }
22
23            // Copy previous best answer
24            if (right > 0)
25                best[right] = best[right - 1];
26
27            // Found a subarray [left ... right]
28            if (sum == target) {
29                int len = right - left + 1;
30
31                // Can combine with a previous non-overlapping subarray
32                if (left > 0 && best[left - 1] != INF) {
33                    ans = min(ans, len + best[left - 1]);
34                }
35
36                // Update best subarray up to right
37                best[right] = min(best[right], len);
38            }
39        }
40
41        return ans == INF ? -1 : ans;
42    }
43};