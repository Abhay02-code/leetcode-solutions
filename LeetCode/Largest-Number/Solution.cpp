1class Solution {
2public:
3    string largestNumber(vector<int>& nums) {
4        vector<string>v;
5        for(int x : nums){
6            v.push_back(to_string(x));
7        }
8        sort(v.begin(), v.end(),[](string a, string b){
9            return a+b>b+a;
10        });
11        if(v[0] == "0") return "0";
12
13        string ans = "";
14
15        for(string y : v){
16            ans += y;
17        }
18        return ans;
19
20        
21    }
22};