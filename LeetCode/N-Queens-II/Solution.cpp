1class Solution {
2public:
3    int ans = 0;
4
5    unordered_set<int> cols;
6    unordered_set<int> diag1;
7    unordered_set<int> diag2;
8
9    void solve(int row, int n) {
10
11        if (row == n) {
12            ans++;
13            return;
14        }
15
16        for (int col = 0; col < n; col++) {
17
18            if (cols.count(col) ||
19                diag1.count(row - col) ||
20                diag2.count(row + col))
21                continue;
22
23            cols.insert(col);
24            diag1.insert(row - col);
25            diag2.insert(row + col);
26
27            solve(row + 1, n);
28
29            cols.erase(col);
30            diag1.erase(row - col);
31            diag2.erase(row + col);
32        }
33    }
34
35    int totalNQueens(int n) {
36
37        solve(0, n);
38        return ans;
39    }
40};