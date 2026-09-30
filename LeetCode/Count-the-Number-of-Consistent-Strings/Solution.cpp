1class Solution {
2public:
3    int countConsistentStrings(string allowed, vector<string>& words) {
4        bool allowedChar[26] = {};
5        for(char ch : allowed){
6            allowedChar[ch - 'a'] = true;
7        }
8        int count = 0;
9        for(string word : words){
10            bool consistent = true;
11
12            for(char ch : word) { if(!allowedChar[ch - 'a']) { 
13                consistent = false; break; 
14                }
15            }
16            if(consistent) {
17                
18             count++; 
19             }
20        }
21        return count;
22        
23    }
24};