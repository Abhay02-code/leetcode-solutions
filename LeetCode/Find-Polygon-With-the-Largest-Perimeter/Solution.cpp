1class Solution {
2public:
3    long long largestPerimeter(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin(),nums.end());
6        long long sum = 0;
7        for(int x : nums){
8            sum += x;
9        }
10        for(int i = n-1; i >= 1; i--){
11            if(sum - nums[i] > nums[i]){
12                return sum;
13            }
14            sum -= nums[i];
15        }
16        return -1;
17
18    }
19};