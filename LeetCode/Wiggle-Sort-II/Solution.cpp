1class Solution {
2public:
3    void wiggleSort(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size();
6        vector<int>temp = nums;
7        
8        int mid = (n+1)/2;
9        int j = mid-1;
10        int k = n-1;
11        for(int i = 0; i < n; i++){
12            if(i%2 ==0) nums[i] = temp[j--];
13            else nums[i] = temp[k--];
14        }
15    }
16};