class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;

        bool increasing = true;
        bool decreasing = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                pos = i;
            }

            int next = nums[(i + 1) % n];

            if (next != (nums[i] + 1) % n) {
                increasing = false;
            }

            if (next != (nums[i] - 1 + n) % n) {
                decreasing = false;
            }
        }

        int ans = INT_MAX;

        if (increasing) {
            ans = min(ans, min(pos, n - pos + 2));
        }

        if (decreasing) {
            int q = n - 1 - pos;
            ans = min(ans, 1 + min(q, n - q));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};