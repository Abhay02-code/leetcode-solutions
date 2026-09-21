1class Solution {
2public:
3    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
4        vector<int>x;
5        for(int i = 0; i < points.size(); i++){
6            x.push_back(points[i][0]);
7        }
8        sort(x.begin(), x.end());
9
10        int ans = INT_MIN;
11        int diff = 0;
12
13        for(int i = 0; i < x.size()-1; i++){
14            diff = x[i+1] - x[i];
15            ans = max(ans, diff);
16        }
17        return ans;
18        
19    }
20};