1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        int minOdd = INT_MAX;
5
6     
7        for (int x : nums1) {
8            if (x % 2 == 1) {
9                minOdd = min(minOdd, x);
10            }
11        }
12
13        if (minOdd == INT_MAX) {
14            return true;
15        }
16
17       
18        for (int x : nums1) {
19            if (x % 2 == 0 && x < minOdd) {
20                return false;
21            }
22        }
23
24        return true;
25    }
26};