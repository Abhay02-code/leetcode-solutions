1class Solution {
2public:
3    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
4        sort(intervals.begin(), intervals.end(),
5            [](vector<int>& a, vector<int>& b) {
6                return a[1] < b[1];
7    });
8    int ans = 0;
9    int prevEnd = intervals[0][1];
10    for(int i = 1; i < intervals.size(); i++){
11        if(intervals[i][0] < prevEnd) ans++;
12        else prevEnd = intervals[i][1];
13    }
14    return ans;
15        
16    }
17};