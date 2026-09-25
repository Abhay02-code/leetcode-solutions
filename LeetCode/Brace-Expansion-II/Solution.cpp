1class Solution {
2public:
3
4    set<string> solve(string s) {
5
6        set<string> ans;
7
8        // First check for top-level comma
9        int balance = 0;
10        int start = 0;
11
12        for (int i = 0; i < s.size(); i++) {
13
14            if (s[i] == '{')
15                balance++;
16
17            else if (s[i] == '}')
18                balance--;
19
20            else if (s[i] == ',' && balance == 0) {
21
22                string left = s.substr(start, i - start);
23                set<string> temp = solve(left);
24
25                ans.insert(temp.begin(), temp.end());
26
27                start = i + 1;
28            }
29        }
30
31        // If comma was found
32        if (start != 0) {
33
34            string right = s.substr(start);
35            set<string> temp = solve(right);
36
37            ans.insert(temp.begin(), temp.end());
38
39            return ans;
40        }
41
42        // No top-level comma -> concatenate
43        set<string> current;
44        current.insert("");
45
46        for (int i = 0; i < s.size(); ) {
47
48            set<string> part;
49
50            if (s[i] == '{') {
51
52                int balance = 1;
53                int j = i + 1;
54
55                while (balance > 0) {
56
57                    if (s[j] == '{')
58                        balance++;
59
60                    else if (s[j] == '}')
61                        balance--;
62
63                    j++;
64                }
65
66                string inside = s.substr(i + 1, j - i - 2);
67
68                part = solve(inside);
69
70                i = j;
71            }
72            else {
73
74                string ch = "";
75                ch += s[i];
76
77                part.insert(ch);
78
79                i++;
80            }
81
82            set<string> next;
83
84            for (string a : current) {
85                for (string b : part) {
86                    next.insert(a + b);
87                }
88            }
89
90            current = next;
91        }
92
93        return current;
94    }
95
96    vector<string> braceExpansionII(string expression) {
97
98        set<string> result = solve(expression);
99
100        return vector<string>(result.begin(), result.end());
101    }
102};