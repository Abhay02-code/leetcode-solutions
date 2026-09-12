1class Solution {
2public:
3
4    struct State {
5        long long score = 0;
6        vector<int> ids;
7    };
8
9    // Return true if a is better than b
10    bool better(const State& a, const State& b) {
11        if (a.score != b.score)
12            return a.score > b.score;
13
14        return a.ids < b.ids;   // lexicographically smaller
15    }
16
17    vector<int> maximumWeight(vector<vector<int>>& intervals) {
18
19        int n = intervals.size();
20
21        // {start, end, weight, original_index}
22        vector<array<long long, 4>> a;
23
24        for (int i = 0; i < n; i++) {
25            a.push_back({
26                intervals[i][0],
27                intervals[i][1],
28                intervals[i][2],
29                i
30            });
31        }
32
33        // Sort by ending time
34        sort(a.begin(), a.end(), [](auto& x, auto& y) {
35            if (x[1] != y[1])
36                return x[1] < y[1];
37
38            return x[0] < y[0];
39        });
40
41        // Store all ending times
42        vector<long long> ends(n);
43
44        for (int i = 0; i < n; i++) {
45            ends[i] = a[i][1];
46        }
47
48        /*
49            prev[i] =
50            number of intervals before i whose end < a[i].start
51
52            Because intervals are inclusive,
53            we need:
54
55                previous_end < current_start
56
57            NOT <=
58        */
59        vector<int> prev(n);
60
61        for (int i = 0; i < n; i++) {
62
63            prev[i] =
64                lower_bound(ends.begin(), ends.end(), a[i][0])
65                - ends.begin();
66
67        }
68
69        /*
70            dp[i][k] =
71            best answer using first i intervals
72            while selecting at most k intervals.
73
74            k <= 4
75        */
76        vector<vector<State>> dp(
77            n + 1,
78            vector<State>(5)
79        );
80
81        for (int i = 1; i <= n; i++) {
82
83            int idx = i - 1;
84
85            for (int k = 1; k <= 4; k++) {
86
87                // Option 1:
88                // Don't take current interval
89                dp[i][k] = dp[i - 1][k];
90
91                // Option 2:
92                // Take current interval
93                State take = dp[prev[idx]][k - 1];
94
95                take.score += a[idx][2];
96
97                take.ids.push_back((int)a[idx][3]);
98
99                // Indices must be sorted for lexicographical comparison
100                sort(take.ids.begin(), take.ids.end());
101
102                if (better(take, dp[i][k])) {
103                    dp[i][k] = take;
104                }
105            }
106        }
107
108        return dp[n][4].ids;
109    }
110};