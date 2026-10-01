1class Solution {
2public:
3
4    vector<int> getMax(vector<int>& a, int k) {
5        vector<int> st;
6        int remove = a.size() - k;
7
8        for (int x : a) {
9            while (!st.empty() && remove && st.back() < x) {
10                st.pop_back();
11                remove--;
12            }
13            st.push_back(x);
14        }
15
16        while (st.size() > k)
17            st.pop_back();
18
19        return st;
20    }
21
22    bool greater(vector<int>& a, int i, vector<int>& b, int j) {
23        while (i < a.size() && j < b.size() && a[i] == b[j])
24            i++, j++;
25
26        return j == b.size() ||
27               (i < a.size() && a[i] > b[j]);
28    }
29
30    vector<int> merge(vector<int>& a, vector<int>& b) {
31        vector<int> ans;
32        int i = 0, j = 0;
33
34        while (i < a.size() || j < b.size()) {
35            if (j == b.size() ||
36                (i < a.size() && greater(a, i, b, j)))
37                ans.push_back(a[i++]);
38            else
39                ans.push_back(b[j++]);
40        }
41
42        return ans;
43    }
44
45    vector<int> maxNumber(vector<int>& a, vector<int>& b, int k) {
46        vector<int> ans;
47
48        for (int i = 0; i <= k; i++) {
49            int j = k - i;
50
51            if (i > a.size() || j > b.size())
52                continue;
53
54            vector<int> x = getMax(a, i);
55            vector<int> y = getMax(b, j);
56            vector<int> cur = merge(x, y);
57
58            if (ans.empty() || greater(cur, 0, ans, 0))
59                ans = cur;
60        }
61
62        return ans;
63    }
64};