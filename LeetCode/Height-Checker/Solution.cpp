1class Solution {
2public:
3    int heightChecker(vector<int>& heights) {
4        vector<int>arr;
5        for(int i = 0; i < heights.size(); i++){
6            arr.push_back(heights[i]);
7        }
8        sort(arr.begin(),arr.end());
9        int count = 0;
10        for(int i = 0; i < heights.size(); i++){
11            if(heights[i] != arr[i]){
12                count++;
13            }
14        }
15        return count;
16        
17    }
18};