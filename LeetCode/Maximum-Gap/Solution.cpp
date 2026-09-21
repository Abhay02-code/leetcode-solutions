1class Solution {
2public:
3    int maximumGap(vector<int>& nums) {
4        if(nums.size() < 2) return 0;
5        sort(nums.begin(), nums.end());
6        int ans = INT_MIN;
7        int diff = 0;
8
9        for(int i = 0; i < nums.size()-1; i++){
10            diff = nums[i+1]-nums[i];
11            ans = max(ans, diff);
12
13        }
14        return ans;
15        
16        
17    }
18};