1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4
5        int n = nums.size();
6        vector<int> ans(n, -1);
7        stack<int> st;
8
9        for (int i = 0; i < 2 * n; i++) {
10
11            int curr = i % n;
12
13            while (!st.empty() && nums[curr] > nums[st.top()]) {
14                ans[st.top()] = nums[curr];
15                st.pop();
16            }
17
18            if (i < n) {
19                st.push(curr);
20            }
21        }
22
23        return ans;
24    }
25};