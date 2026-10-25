class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        vector<long long>gain(n);
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int digit[10] = {0};
            while(x>0){
                digit[x%10]++;
                x /= 10;
            }
            long long val = 0;
            for(int d = 9; d >= 0; d--){
                while(digit[d] > 0){
                    val = val * 10 + d;
                    digit[d]--;
                }
            }
           gain[i] = val - nums[i];
           sum += nums[i];
        }
        sort(gain.begin(),gain.end(),greater<long long>());
        for(int i = 0; i < k; i++){
            if(gain[i] > 0) sum += gain[i];
        }
        
        return sum;
        
    }
};