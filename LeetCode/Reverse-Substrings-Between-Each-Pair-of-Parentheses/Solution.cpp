1class Solution {
2public:
3    string reverseParentheses(string s) {
4        
5        stack<string> st;
6        string curr = "";
7
8        for(char ch : s) {
9            
10            if(ch == '(') {
11                st.push(curr);
12                curr = "";
13            }
14            else if(ch == ')') {
15                reverse(curr.begin(), curr.end());
16                curr = st.top()+curr;
17                st.pop();
18            }
19            else {
20                curr += ch;
21            }
22        }
23
24        return curr;
25    }
26};