1class Solution {
2public:
3    int deleteAndEarn(vector<int>& nums) {
4
5        int max1 = *max_element(nums.begin(), nums.end());
6        vector<int>dp(max1+1, 0);
7
8        for(int num : nums) dp[num] += num;
9
10        int prev2 = 0;
11        int prev1 = dp[0];
12
13        for(int i = 1; i <= max1; i++){
14            int take = dp[i] + prev2;
15            int skip = prev1;
16
17            int curr = max(take, skip);
18
19            prev2 = prev1;
20            prev1 = curr;
21
22        }
23        return prev1;
24    }
25};