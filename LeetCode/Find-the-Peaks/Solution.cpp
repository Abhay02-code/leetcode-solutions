1class Solution {
2public:
3    vector<int> findPeaks(vector<int>& mountain) {
4        vector<int> ans;
5        for(int i = 1; i < mountain.size()-1; i++){
6            if(mountain[i-1] < mountain[i] && mountain[i] > mountain[i+1]) ans.push_back(i);
7        }
8        return ans;
9    }
10};