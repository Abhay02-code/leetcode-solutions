1class Solution {
2public:
3    bool isValid(string st) {
4        stack<char> s;
5        for(char c : st){
6            if(c == '(' || c == '{' || c == '[')
7            s.push(c);
8            else{
9                if(s.empty()) return false;
10                char top = s.top();
11                if((c == ')' && top == '(')||
12                 (c == '}' && top == '{') ||
13                  (c == ']' && top == '[')){
14                    s.pop();
15                  }else{
16                    return false;
17                  }
18
19            }
20
21        }
22        return s.empty();
23        
24    }
25};