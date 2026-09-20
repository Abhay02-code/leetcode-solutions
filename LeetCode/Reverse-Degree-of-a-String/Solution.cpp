1class Solution {
2public:
3    int reverseDegree(string s) {
4        int ans = 0;
5
6        for (int i = 0; i < s.size(); i++) {
7            int degree = 'z' - s[i] + 1;
8            ans += degree * (i + 1);
9        }
10
11        return ans;
12    }
13};