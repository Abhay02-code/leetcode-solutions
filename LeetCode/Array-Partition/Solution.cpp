1class Solution {
2public:
3    int arrayPairSum(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5
6        int sum = 0;
7
8        for(int i = 0; i < nums.size(); i += 2) {
9            sum += nums[i];
10        }
11
12        return sum;
13    }
14};