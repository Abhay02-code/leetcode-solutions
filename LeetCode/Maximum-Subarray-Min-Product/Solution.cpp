1class Solution {
2public:
3    int maxSumMinProduct(vector<int>& nums) {
4
5        int n = nums.size();
6
7        // Prefix sum
8        vector<long long> prefix(n + 1, 0);
9
10        for (int i = 0; i < n; i++) {
11            prefix[i + 1] = prefix[i] + nums[i];
12        }
13
14        stack<int> st;
15        long long ans = 0;
16
17        // Extra iteration to empty the stack
18        for (int i = 0; i <= n; i++) {
19
20            while (!st.empty() &&
21                   (i == n || nums[st.top()] > nums[i])) {
22
23                int idx = st.top();
24                st.pop();
25
26                // Left boundary
27                int left = st.empty() ? 0 : st.top() + 1;
28
29                // Right boundary
30                int right = i - 1;
31
32                // Sum of subarray [left ... right]
33                long long sum = prefix[i] - prefix[left];
34
35                // Minimum × Sum
36                long long product = 1LL * nums[idx] * sum;
37
38                ans = max(ans, product);
39            }
40
41            // Don't push the imaginary element at i == n
42            if (i < n) {
43                st.push(i);
44            }
45        }
46
47        return ans % 1000000007;
48    }
49};