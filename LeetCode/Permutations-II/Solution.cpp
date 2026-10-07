1class Solution {
2public:
3    vector<vector<int>> result;
4
5    void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& used) {
6        if (temp.size() == nums.size()) {
7            result.push_back(temp);
8            return;
9        }
10
11        for (int i = 0; i < nums.size(); i++) {
12
13            if (used[i]) continue;
14
15            
16            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
17                continue;
18
19            used[i] = true;
20            temp.push_back(nums[i]);
21
22            backtrack(nums, temp, used);
23
24            temp.pop_back();
25            used[i] = false;
26        }
27    }
28
29    vector<vector<int>> permuteUnique(vector<int>& nums) {
30        sort(nums.begin(), nums.end());
31
32        vector<int> temp;
33        vector<bool> used(nums.size(), false);
34
35        backtrack(nums, temp, used);
36        return result;
37    }
38};
39