1class Solution {
2public:
3    string removeDuplicates(string s) {
4        stack<char>st;
5        for(int i = 0; i < s.size(); i++){
6            if(!st.empty() && st.top() == s[i]){
7                st.pop();
8                
9            }
10            else{
11                st.push(s[i]);
12            }
13
14        }
15        string ans = "";
16        while(!st.empty()){
17            ans += st.top();
18            st.pop();
19        }
20        reverse(ans.begin(),ans.end());
21        return ans;
22        
23    }
24};