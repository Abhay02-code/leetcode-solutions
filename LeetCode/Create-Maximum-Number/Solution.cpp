1class Solution {
2public:
3
4    vector<int> getMax(vector<int>& nums, int k) {
5    
6        // monotonic stack
7        vector<int>st;
8        int remove = nums.size()-k;
9        for(int x : nums){
10            while(!st.empty() && remove > 0 && st.back() < x){
11            st.pop_back();
12            remove--;
13
14           }
15           st.push_back(x);
16        }
17        while(st.size()>k){
18            st.pop_back();
19        }
20        return st;
21    }
22
23    bool greater(vector<int>& a, int i,
24                 vector<int>& b, int j) {
25        // compare remaining elements
26         while (i < a.size() &&
27               j < b.size() &&
28               a[i] == b[j]) {
29
30            i++;
31            j++;
32        }
33
34        // b is finished
35        if (j == b.size())
36            return true;
37
38        // a is finished
39        if (i == a.size())
40            return false;
41
42        return a[i] > b[j];
43    }
44
45    vector<int> merge(vector<int>& a,
46                      vector<int>& b) {
47
48        // choose larger remaining sequence
49        vector<int>ans;
50        int i = 0;
51        int j = 0;
52        while (i < a.size() || j < b.size()) {
53
54        if (i == a.size()) {
55            ans.push_back(b[j]);
56            j++;
57        }
58        else if (j == b.size()) {
59            ans.push_back(a[i]);
60            i++;
61        }
62        else if (greater(a, i, b, j)) {
63            ans.push_back(a[i]);
64            i++;
65        }
66        else {
67            ans.push_back(b[j]);
68            j++;
69        }
70    }
71
72    return ans;
73    }
74
75    vector<int> maxNumber(vector<int>& nums1,
76                          vector<int>& nums2,
77                          int k) {
78
79        // try every possible split
80        vector<int> answer;
81
82        // Try every possible number of elements
83        // taken from nums1
84        for (int i = 0; i <= k; i++) {
85
86            int j = k - i;
87
88            // Invalid split
89            if (i > nums1.size() ||
90                j > nums2.size()) {
91                continue;
92            }
93
94            // Maximum subsequence from each array
95            vector<int> a = getMax(nums1, i);
96            vector<int> b = getMax(nums2, j);
97
98            // Merge them
99            vector<int> candidate = merge(a, b);
100
101            // Keep the larger answer
102            if (greater(candidate, 0,
103                        answer, 0)) {
104
105                answer = candidate;
106            }
107        }
108
109        return answer;
110    }
111};