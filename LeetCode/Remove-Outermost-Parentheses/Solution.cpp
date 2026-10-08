1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4        int count = 0;
5        string ans = "";
6        for(char c : s){
7            if(c == '('){
8                
9                if(count > 0){
10                    ans += c;
11                   
12                }
13                count++;
14            }
15            else{
16                count--;
17                if(count > 0){
18                    ans += c;
19                }
20            }
21        }
22        return ans;
23
24        
25
26    }
27};