1
2class Solution {
3public:
4    vector<int> powerfulIntegers(int x, int y, int bound) {
5        set<int> s;
6
7        for (int i = 1; i <= bound; i *= x) {
8            for (int j = 1; i + j <= bound; j *= y) {
9                s.insert(i + j);
10
11                if (y == 1) break;
12            }
13
14            if (x == 1) break;
15        }
16
17        return vector<int>(s.begin(), s.end());
18    }
19};
20