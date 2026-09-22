1class Solution {
2public:
3    struct Node {
4        int prod;
5        int cnt[5];
6
7        Node() {
8            prod = 1;
9            for (int i = 0; i < 5; i++)
10                cnt[i] = 0;
11        }
12    };
13
14    int k;
15    vector<Node> tree;
16
17    Node merge(Node &a, Node &b) {
18        Node res;
19
20        res.prod = (a.prod * b.prod) % k;
21
22        for (int r = 0; r < k; r++) {
23            res.cnt[r] += a.cnt[r];
24        }
25
26        for (int r = 0; r < k; r++) {
27            int nr = (a.prod * r) % k;
28            res.cnt[nr] += b.cnt[r];
29        }
30
31        return res;
32    }
33
34    void build(vector<int>& nums, int node, int l, int r) {
35        if (l == r) {
36            tree[node].prod = nums[l] % k;
37            tree[node].cnt[nums[l] % k] = 1;
38            return;
39        }
40
41        int mid = (l + r) / 2;
42
43        build(nums, node * 2, l, mid);
44        build(nums, node * 2 + 1, mid + 1, r);
45
46        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
47    }
48
49    void update(int node, int l, int r, int idx, int value) {
50        if (l == r) {
51            for (int i = 0; i < 5; i++)
52                tree[node].cnt[i] = 0;
53
54            tree[node].prod = value % k;
55            tree[node].cnt[value % k] = 1;
56
57            return;
58        }
59
60        int mid = (l + r) / 2;
61
62        if (idx <= mid)
63            update(node * 2, l, mid, idx, value);
64        else
65            update(node * 2 + 1, mid + 1, r, idx, value);
66
67        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
68    }
69
70    Node query(int node, int l, int r, int ql, int qr) {
71        if (ql <= l && r <= qr)
72            return tree[node];
73
74        int mid = (l + r) / 2;
75
76        if (qr <= mid)
77            return query(node * 2, l, mid, ql, qr);
78
79        if (ql > mid)
80            return query(node * 2 + 1, mid + 1, r, ql, qr);
81
82        Node left = query(node * 2, l, mid, ql, qr);
83        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);
84
85        return merge(left, right);
86    }
87
88    vector<int> resultArray(vector<int>& nums, int k,
89                            vector<vector<int>>& queries) {
90
91        this->k = k;
92
93        int n = nums.size();
94
95        tree.resize(4 * n);
96
97        build(nums, 1, 0, n - 1);
98
99        vector<int> ans;
100
101        for (auto &q : queries) {
102            int index = q[0];
103            int value = q[1];
104            int start = q[2];
105            int x = q[3];
106
107            nums[index] = value;
108
109            update(1, 0, n - 1, index, value);
110
111            Node res = query(1, 0, n - 1, start, n - 1);
112
113            ans.push_back(res.cnt[x]);
114        }
115
116        return ans;
117    }
118};