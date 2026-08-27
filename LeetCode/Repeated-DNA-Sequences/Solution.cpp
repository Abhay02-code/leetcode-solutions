1class Solution {
2public:
3    vector<string> findRepeatedDnaSequences(string s) {
4        int n = s.size();
5        vector<string>ans;
6        unordered_map<string,int>freq;
7        if(n < 10) return ans;
8        for(int i = 0; i <= n-10; i++){
9            string sub = s.substr(i, 10);
10            freq[sub]++;
11
12            if(freq[sub] == 2){
13                ans.push_back(sub);
14            }
15        }
16        return ans;
17
18        
19    }
20};