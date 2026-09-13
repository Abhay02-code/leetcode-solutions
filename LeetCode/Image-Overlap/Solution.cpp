1class Solution {
2public:
3    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
4        int n = img1.size();
5
6        vector<pair<int, int>> a, b;
7
8        // Store coordinates of all 1s
9        for (int i = 0; i < n; i++) {
10            for (int j = 0; j < n; j++) {
11                if (img1[i][j] == 1)
12                    a.push_back({i, j});
13
14                if (img2[i][j] == 1)
15                    b.push_back({i, j});
16            }
17        }
18
19        map<pair<int, int>, int> mp;
20
21        int ans = 0;
22
23        // Compare every 1 in img1 with every 1 in img2
24        for (auto p : a) {
25            for (auto q : b) {
26                int dx = q.first - p.first;
27                int dy = q.second - p.second;
28
29                mp[{dx, dy}]++;
30
31                ans = max(ans, mp[{dx, dy}]);
32            }
33        }
34
35        return ans;
36    }
37};