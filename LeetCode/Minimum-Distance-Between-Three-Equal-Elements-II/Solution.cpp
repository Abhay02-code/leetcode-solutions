1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4       unordered_map<int, vector<int>>mp;
5       for(int i = 0; i < nums.size(); i++){
6        mp[nums[i]].push_back(i);
7
8       }
9        int ans = INT_MAX;
10        for(auto &p : mp){
11            vector<int>& v = p.second;
12            for(int i = 0; i+2 < v.size(); i++){
13                int first = v[i];
14                int third = v[i+2];
15
16                 int distance = 2 * (third - first);
17
18                ans = min(ans, distance);
19            }
20        }
21        if(ans == INT_MAX) return -1;
22
23        return ans;
24        
25    }
26};