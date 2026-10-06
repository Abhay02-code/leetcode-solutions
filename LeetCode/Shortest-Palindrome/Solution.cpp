1class Solution {
2public:
3    string shortestPalindrome(string s) {
4        int n = s.size();
5
6        if (n <= 1) return s;
7
8        string rev = s;
9        reverse(rev.begin(), rev.end());
10
11        string t;
12        t.reserve(2 * n + 1);
13        t += s;
14        t += '#';
15        t += rev;
16
17        vector<int> lps(2 * n + 1, 0);
18
19        int j = 0;
20
21        for (int i = 1; i < t.size(); i++) {
22            while (j > 0 && t[i] != t[j])
23                j = lps[j - 1];
24
25            if (t[i] == t[j])
26                j++;
27
28            lps[i] = j;
29        }
30
31        int len = lps.back();
32
33        string ans;
34        ans.reserve(2 * n - len);
35
36        // Add remaining characters in reverse order
37        for (int i = n - 1; i >= len; i--)
38            ans += s[i];
39
40        ans += s;
41
42        return ans;
43    }
44};