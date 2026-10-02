1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4
5        stack<int> st;
6        int area = 0;
7
8        for(int i = 0; i < heights.size(); i++) {
9
10            while(!st.empty() && heights[i] < heights[st.top()]) {
11
12                int h = heights[st.top()];
13                st.pop();
14
15                int width;
16
17                if(st.empty())
18                    width = i;
19                else
20                    width = i - st.top() - 1;
21
22                area = max(area, h * width);
23            }
24
25            st.push(i);
26        }
27
28        // Process remaining elements
29        while(!st.empty()) {
30
31            int h = heights[st.top()];
32            st.pop();
33
34            int width;
35
36            if(st.empty())
37                width = heights.size();
38            else
39                width = heights.size() - st.top() - 1;
40
41            area = max(area, h * width);
42        }
43
44        return area;
45    }
46};