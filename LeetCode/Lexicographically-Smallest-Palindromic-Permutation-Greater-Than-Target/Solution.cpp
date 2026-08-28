1class Solution {
2public:
3    string lexPalindromicPermutation(string s, string target) {
4        int n = s.size();
5        int k = n / 2;
6        vector<int> freq(26, 0);
7        for (char c : s) freq[c - 'a']++;
8
9        vector<int> oddChars;
10        for (int i = 0; i < 26; i++)
11            if (freq[i] % 2) oddChars.push_back(i);
12
13        char mid = 0;
14        bool hasMid = false;
15        if (n % 2 == 0) {
16            if (!oddChars.empty()) return "";
17        } else {
18            if (oddChars.size() != 1) return "";
19            mid = 'a' + oddChars[0];
20            hasMid = true;
21        }
22
23        vector<int> leftCounts(26, 0);
24        for (int i = 0; i < 26; i++) leftCounts[i] = freq[i] / 2;
25
26        string tl = target.substr(0, k);
27        string tr = target.substr(k);
28
29        vector<vector<int>> countsAt;
30        countsAt.push_back(leftCounts);
31        vector<int> cur = leftCounts;
32        int t = 0;
33        for (int i = 0; i < k; i++) {
34            int ci = tl[i] - 'a';
35            if (cur[ci] > 0) {
36                cur[ci]--;
37                countsAt.push_back(cur);
38                t++;
39            } else {
40                break;
41            }
42        }
43
44        auto fillSorted = [&](vector<int> counts) -> string {
45            string out;
46            for (int i = 0; i < 26; i++)
47                out.append(counts[i], char('a' + i));
48            return out;
49        };
50
51        auto buildPalindrome = [&](const string& left) -> string {
52            string res = left;
53            if (hasMid) res += mid;
54            for (int i = (int)left.size() - 1; i >= 0; i--) res += left[i];
55            return res;
56        };
57
58        int start;
59        if (t == k) {
60            string suffix;
61            if (hasMid) suffix += mid;
62            for (int i = k - 1; i >= 0; i--) suffix += tl[i];
63            if (suffix > tr) {
64                return tl + suffix;
65            }
66            start = k - 1;
67        } else {
68            start = t;
69        }
70
71        for (int i = start; i >= 0; i--) {
72            vector<int> counts = countsAt[i];
73            int targetChar = tl[i] - 'a';
74            int pick = -1;
75            for (int c = targetChar + 1; c < 26; c++) {
76                if (counts[c] > 0) { pick = c; break; }
77            }
78            if (pick == -1) continue;
79
80            counts[pick]--;
81            string left = tl.substr(0, i) + char('a' + pick) + fillSorted(counts);
82            return buildPalindrome(left);
83        }
84
85        return "";
86    }
87};