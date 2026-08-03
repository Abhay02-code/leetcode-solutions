1class Solution {
2public:
3    int numRookCaptures(vector<vector<char>>& board) {
4
5        int row = -1, col = -1;
6
7        for (int i = 0; i < 8; i++) {
8            for (int j = 0; j < 8; j++) {
9                if (board[i][j] == 'R') {
10                    row = i;
11                    col = j;
12                    break;
13                }
14            }
15            if (row != -1) break;
16        }
17
18        int ans = 0;
19
20        
21        vector<pair<int, int>> dir = {
22            {-1, 0},
23            {1, 0},
24            {0, -1},
25            {0, 1}
26        };
27
28        for (auto d : dir) {
29            int x = row + d.first;
30            int y = col + d.second;
31
32            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
33
34                if (board[x][y] == 'B')
35                    break;
36
37                if (board[x][y] == 'p') {
38                    ans++;
39                    break;
40                }
41
42                x += d.first;
43                y += d.second;
44            }
45        }
46
47        return ans;
48    }
49};