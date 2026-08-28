1class Solution {
2public:
3    double findMaxAverage(vector<int>& nums, int k) {
4        int n = nums.size();
5        double avgsum = 0, max_avgsum = 0;
6        for(int i = 0; i < k; i++){
7            avgsum += nums[i];
8            
9        }
10        max_avgsum = avgsum;
11        for(int i = k; i < n; i++){
12           avgsum += nums[i] - nums[i-k];
13           max_avgsum = max(max_avgsum, avgsum);
14        }
15        return max_avgsum/k;
16        
17    }
18};