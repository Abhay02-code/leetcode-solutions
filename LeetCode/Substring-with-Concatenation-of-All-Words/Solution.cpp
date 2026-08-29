1class Solution {
2public:
3    vector<int> findSubstring(string s, vector<string>& words) {
4
5        vector<int> ans;
6
7        int wordLen = words[0].size();
8        int wordCount = words.size();
9        int totalLen = wordLen * wordCount;
10
11   
12        unordered_map<string, int> freq;
13
14        for (string word : words) {
15            freq[word]++;
16        }
17
18      
19        for (int i = 0; i < wordLen; i++) {
20
21            int left = i;
22            int count = 0;
23
24           
25            unordered_map<string, int> window;
26
27            for (int right = i; right + wordLen <= s.size(); right += wordLen) {
28
29               
30                string word = s.substr(right, wordLen);
31
32               
33                if (freq.find(word) == freq.end()) {
34
35                    window.clear();
36                    count = 0;
37                    left = right + wordLen;
38
39                    continue;
40                }
41
42                
43                window[word]++;
44                count++;
45
46               
47                while (window[word] > freq[word]) {
48
49                    string leftWord = s.substr(left, wordLen);
50
51                    window[leftWord]--;
52                    left += wordLen;
53                    count--;
54                }
55
56                if (count == wordCount) {
57                    ans.push_back(left);
58
59                    
60                    string leftWord = s.substr(left, wordLen);
61
62                    window[leftWord]--;
63                    left += wordLen;
64                    count--;
65                }
66            }
67        }
68
69        return ans;
70    }
71};