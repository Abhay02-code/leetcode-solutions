1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4        stack<int> st;
5        heights.push_back(0);   // Sentinel
6        int ans = 0;
7
8        for (int i = 0; i < heights.size(); i++) {
9            while (!st.empty() && heights[st.top()] > heights[i]) {
10                int h = heights[st.top()];
11                st.pop();
12
13                int width = st.empty() ? i : i - st.top() - 1;
14                ans = max(ans, h * width);
15            }
16            st.push(i);
17        }
18
19        heights.pop_back();
20        return ans;
21    }
22
23    int maximalRectangle(vector<vector<char>>& matrix) {
24        if (matrix.empty()) return 0;
25
26        int m = matrix.size();
27        int n = matrix[0].size();
28
29        vector<int> heights(n, 0);
30        int ans = 0;
31
32        for (int i = 0; i < m; i++) {
33            for (int j = 0; j < n; j++) {
34                if (matrix[i][j] == '1')
35                    heights[j]++;
36                else
37                    heights[j] = 0;
38            }
39
40            ans = max(ans, largestRectangleArea(heights));
41        }
42
43        return ans;
44    }
45};