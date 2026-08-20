1class Solution {
2public:
3    vector<int> resultArray(vector<int>& nums) {
4        vector<int>arr1;
5        vector<int>arr2;
6
7        arr1.push_back(nums[0]);
8        arr2.push_back(nums[1]);
9
10        for(int i = 2; i < nums.size(); i++){
11            if(arr1.back() > arr2.back()){
12                arr1.push_back(nums[i]);
13            }
14            else{
15                arr2.push_back(nums[i]);
16            }
17        }
18        for(int x: arr2){
19            arr1.push_back(x);
20        }
21        return arr1;
22        
23    }
24};