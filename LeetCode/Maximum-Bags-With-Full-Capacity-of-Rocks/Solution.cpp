1class Solution {
2public:
3    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
4
5        vector<int> need;
6
7        for(int i = 0; i < capacity.size(); i++) {
8            need.push_back(capacity[i] - rocks[i]);
9        }
10
11        sort(need.begin(), need.end());
12
13        int count = 0;
14
15        for(int i = 0; i < need.size(); i++) {
16
17            if(additionalRocks >= need[i]) {
18                additionalRocks -= need[i];
19                count++;
20            }
21            else {
22                break;
23            }
24        }
25
26        return count;
27    }
28};