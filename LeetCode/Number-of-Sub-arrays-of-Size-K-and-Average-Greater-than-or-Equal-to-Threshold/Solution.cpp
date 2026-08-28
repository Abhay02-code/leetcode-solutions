1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
4        int n = arr.size();
5        int ans = 0;
6        int sum = 0;
7
8        for(int i = 0; i < n; i++){
9            sum += arr[i];
10            if(i >= k-1){
11                if(sum >= k * threshold){
12                    ans++;
13                }
14                sum -= arr[i-k+1];
15            }
16
17        }
18        return ans;
19        
20    }
21};