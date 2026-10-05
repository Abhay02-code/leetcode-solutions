1class Solution {
2public:
3    string removeDuplicates(string s, int k) {
4        stack<pair<char,int>>st;
5        for(int i = 0; i < s.size(); i++){
6            if(!st.empty() && st.top().first == s[i]){
7                st.top().second++;
8                if(st.top().second == k){
9                    st.pop();
10                }
11            }
12            else{
13                st.push({s[i],1});
14            }
15        }
16        string ans = "";
17        while(!st.empty()){
18            ans += string(st.top().second,st.top().first);
19            st.pop();
20        }
21        reverse(ans.begin(),ans.end());
22        return ans;
23        
24    }
25};