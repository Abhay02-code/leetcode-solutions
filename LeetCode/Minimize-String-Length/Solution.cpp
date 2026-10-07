1class Solution {
2public:
3    int minimizedStringLength(string s) {
4        
5        unordered_set<char>st;
6        for(char x : s){
7            st.insert(x);
8        }
9        return st.size();
10    }
11};