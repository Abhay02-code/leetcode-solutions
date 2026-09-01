1class Solution {
2public:
3    int minMoves(vector<string>& classroom, int energy) {
4        int m = classroom.size();
5        int n = classroom[0].size();
6
7        // Map each litter cell to a bit number
8        vector<vector<int>> litterId(m, vector<int>(n, -1));
9
10        int sr, sc;
11        int litterCount = 0;
12
13        for (int i = 0; i < m; i++) {
14            for (int j = 0; j < n; j++) {
15
16                if (classroom[i][j] == 'S') {
17                    sr = i;
18                    sc = j;
19                }
20
21                if (classroom[i][j] == 'L') {
22                    litterId[i][j] = litterCount++;
23                }
24            }
25        }
26
27        int targetMask = (1 << litterCount) - 1;
28
29        // visited[row][col][energy][mask]
30        vector<vector<vector<vector<bool>>>> visited(
31            m,
32            vector<vector<vector<bool>>>(
33                n,
34                vector<vector<bool>>(
35                    energy + 1,
36                    vector<bool>(1 << litterCount, false)
37                )
38            )
39        );
40
41        // row, col, remaining energy, mask
42        queue<tuple<int, int, int, int>> q;
43
44        q.push({sr, sc, energy, 0});
45        visited[sr][sc][energy][0] = true;
46
47        int moves = 0;
48
49        int dr[] = {-1, 1, 0, 0};
50        int dc[] = {0, 0, -1, 1};
51
52        while (!q.empty()) {
53
54            int size = q.size();
55
56            while (size--) {
57
58                auto [r, c, currEnergy, mask] = q.front();
59                q.pop();
60
61                // All litter collected
62                if (mask == targetMask)
63                    return moves;
64
65                for (int d = 0; d < 4; d++) {
66
67                    int nr = r + dr[d];
68                    int nc = c + dc[d];
69
70                    // Outside grid
71                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
72                        continue;
73
74                    // Obstacle
75                    if (classroom[nr][nc] == 'X')
76                        continue;
77
78                    // No energy to make this move
79                    if (currEnergy == 0)
80                        continue;
81
82                    int newEnergy = currEnergy - 1;
83                    int newMask = mask;
84
85                    // Collect litter
86                    if (classroom[nr][nc] == 'L') {
87                        int id = litterId[nr][nc];
88                        newMask |= (1 << id);
89                    }
90
91                    // Reset energy
92                    if (classroom[nr][nc] == 'R') {
93                        newEnergy = energy;
94                    }
95
96                    // Avoid repeated state
97                    if (!visited[nr][nc][newEnergy][newMask]) {
98
99                        visited[nr][nc][newEnergy][newMask] = true;
100
101                        q.push({
102                            nr,
103                            nc,
104                            newEnergy,
105                            newMask
106                        });
107                    }
108                }
109            }
110
111            moves++;
112        }
113
114        return -1;
115    }
116};