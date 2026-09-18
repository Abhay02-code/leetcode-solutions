1class Solution {
2public:
3    vector<string> maxNumOfSubstrings(string s) {
4        int n = s.size();
5        vector<int> first(26, n), last(26, -1);
6
7        for (int i = 0; i < n; i++) {
8            int x = s[i] - 'a';
9            first[x] = min(first[x], i);
10            last[x] = i;
11        }
12
13        vector<pair<int, int>> intervals;
14
15        for (int c = 0; c < 26; c++) {
16            if (last[c] == -1) continue;
17
18            int l = first[c];
19            int r = last[c];
20            bool valid = true;
21
22            for (int i = l; i <= r; i++) {
23                int x = s[i] - 'a';
24
25                if (first[x] < l) {
26                    valid = false;
27                    break;
28                }
29
30                r = max(r, last[x]);
31            }
32
33            if (valid)
34                intervals.push_back({l, r});
35        }
36
37        sort(intervals.begin(), intervals.end(),
38             [](auto &a, auto &b) {
39                 return a.second < b.second;
40             });
41
42        vector<string> ans;
43        int prev = -1;
44
45        for (auto [l, r] : intervals) {
46            if (l > prev) {
47                ans.push_back(s.substr(l, r - l + 1));
48                prev = r;
49            }
50        }
51
52        return ans;
53    }
54};