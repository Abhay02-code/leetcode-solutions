1class Solution {
2public:
3    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
4        vector<int>temp;
5        priority_queue<int>pq;
6        for(int i = 0; i < queries.size(); i++){
7            int dist = abs(queries[i][0]) + abs(queries[i][1]);
8            pq.push(dist);
9            if(pq.size()>k){
10                pq.pop();
11
12            }
13            if(pq.size()<k){
14                temp.push_back(-1);
15            }
16            else{
17                temp.push_back(pq.top());
18            }
19        }
20        return temp;
21
22        
23    }
24};