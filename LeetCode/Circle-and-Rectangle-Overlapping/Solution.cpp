1class Solution {
2public:
3    bool checkOverlap(int radius, int xCenter, int yCenter,
4                      int x1, int y1, int x2, int y2) {
5        
6        int x = max(x1, min(xCenter, x2));
7        int y = max(y1, min(yCenter, y2));
8
9        int dx = xCenter - x;
10        int dy = yCenter - y;
11
12        return dx * dx + dy * dy <= radius * radius;
13    }
14};