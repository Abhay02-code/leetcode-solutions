1class Solution {
2public:
3
4    vector<string> ans;
5    unordered_set<string> visited;
6
7    int getInvalid(string s) {
8
9        stack<char> st;
10
11        int i = 0;
12
13        while (i < s.size()) {
14
15            if (s[i] == '(') {
16                st.push(s[i]);
17            }
18
19            else if (s[i] == ')') {
20
21                if (!st.empty() && st.top() == '(') {
22                    st.pop();
23                }
24                else {
25                    st.push(')');
26                }
27            }
28
29            i++;
30        }
31
32        return st.size();
33    }
34
35    void solve(string s, int minInv) {
36
37        // already solved this string
38        if (visited.find(s) != visited.end()) {
39            return;
40        }
41
42        visited.insert(s);
43
44        if (minInv == 0) {
45
46            if (getInvalid(s) == 0) {
47                ans.push_back(s);
48            }
49
50            return;
51        }
52
53        for (int i = 0; i < s.size(); i++) {
54
55            if (s[i] != '(' && s[i] != ')') {
56                continue;
57            }
58
59            if (i > 0 && s[i] == s[i - 1]) {
60                continue;
61            }
62
63            string newString = s.substr(0, i) + s.substr(i + 1);
64
65            solve(newString, minInv - 1);
66        }
67    }
68
69    vector<string> removeInvalidParentheses(string s) {
70
71        int minInv = getInvalid(s);
72
73        solve(s, minInv);
74
75        return ans;
76    }
77};