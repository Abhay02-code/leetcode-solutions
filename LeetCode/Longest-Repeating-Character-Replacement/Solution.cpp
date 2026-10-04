1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4
5        unordered_map<char, int> mp;
6
7        int left = 0;
8        int ans = 0;
9        int maxFreq = 0;
10
11        for(int right = 0; right < s.size(); right++) {
12
13            mp[s[right]]++;
14
15            maxFreq = max(maxFreq, mp[s[right]]);
16
17            while((right - left + 1) - maxFreq > k) {
18                mp[s[left]]--;
19                left++;
20            }
21
22            ans = max(ans, right - left + 1);
23        }
24
25        return ans;
26    }
27};