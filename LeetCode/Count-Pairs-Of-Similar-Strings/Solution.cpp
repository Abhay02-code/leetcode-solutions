1class Solution {
2public:
3    int similarPairs(vector<string>& words) {
4        unordered_map<int,int>mp;
5        int ans = 0;
6        for(string s : words){
7            int m = 0;
8            for(char ch : s){
9                int bit = ch - 'a';
10                m = m|(1<<bit);
11            }
12            ans += mp[m];
13            mp[m]++;
14        }
15        return ans;
16        
17    }
18};