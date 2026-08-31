1class Solution {
2public:
3
4    bool canSplit(vector<int>& nums, int k, int mid){
5        int subArray = 1;
6        int sum = 0;
7         for (int num : nums) {
8
9            if (sum + num > mid) {
10              
11                subArray++;
12                sum = num;
13
14                if (subArray > k)
15                    return false;
16            }
17            else {
18                sum += num;
19            }
20        }
21
22        return true;
23    }
24    int splitArray(vector<int>& nums, int k) {
25        int l= *max_element(nums.begin(), nums.end());
26        int h = accumulate(nums.begin(), nums.end(), 0);
27
28        while(l < h){
29            int mid = l + (h-l)/2;
30            if(canSplit(nums, k, mid)){
31                h = mid;
32            }
33            else{
34                l = mid+1;
35
36            }
37        }
38        return l;
39        
40    }
41};