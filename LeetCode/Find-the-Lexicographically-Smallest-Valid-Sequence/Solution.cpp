1class Solution {
2public:
3    vector<int> validSequence(string word1, string word2) {
4
5        int n = word1.size();
6        int m = word2.size();
7
8        
9        vector<int> suf(n + 1, 0);
10
11        int j = m - 1;
12
13        for (int i = n - 1; i >= 0; i--) {
14            suf[i] = suf[i + 1];
15
16            if (j >= 0 && word1[i] == word2[j]) {
17                suf[i]++;
18                j--;
19            }
20        }
21
22        vector<int> ans;
23
24        int pos = 0;
25        bool used = false;
26
27        for (int i = 0; i < m; i++) {
28
29            while (pos < n) {
30
31                if (word1[pos] == word2[i]) {
32                    ans.push_back(pos);
33                    pos++;
34                    break;
35                }
36
37                if (!used) {
38
39                   
40                    int remaining = m - i - 1;
41
42                    if (suf[pos + 1] >= remaining) {
43
44                        ans.push_back(pos);
45                        pos++;
46                        used = true;
47                        break;
48                    }
49                }
50
51                pos++;
52            }
53
54            if (ans.size() != i + 1)
55                return {};
56        }
57
58        return ans;
59    }
60};