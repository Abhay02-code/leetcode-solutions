1class Solution {
2public:
3    int maxScore(vector<int>& nums, int k) {
4        
5        int n = nums.size();
6        int l = k-1;
7        int r = n-1;
8        int i = 0;
9        int sum = 0;
10        while(i < k){
11            sum += nums[i];
12            i++;
13        }
14        int ans = sum;
15        int operation = 0;
16        while(operation < k){
17            sum -= nums[l];
18            sum += nums[r];
19
20            ans = max(ans,sum);
21            l--;
22            r--;
23            operation++;
24
25
26        }
27        return ans;
28    }
29};