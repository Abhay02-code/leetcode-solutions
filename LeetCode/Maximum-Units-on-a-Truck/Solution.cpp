1class Solution {
2public:
3    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
4        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>a,vector<int>b){
5             return a[1] > b[1];
6        });
7        int ans = 0;
8        for(int i = 0; i < boxTypes.size(); i++){
9            int boxes = boxTypes[i][0];
10            int units = boxTypes[i][1];
11
12            int take = min(boxes, truckSize);
13
14            ans += take * units;
15
16            truckSize -= take;
17
18            if(truckSize == 0){
19                break;
20            }
21
22
23        }
24        return ans;
25        
26    }
27};