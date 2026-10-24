class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        long long ans = 0;
        for(int j = 0; j < n-1; j++){
            int left[27] = {0};
            int right[27] = {0};
            bool seen[26] = {false};
            int distinct = 0;
            for(int i = j; i >=0; i--){
                if(!seen[s[i]-'a']){
                    seen[s[i]-'a'] = true;
                    distinct++;
                }
                left[distinct]++;
            }
            for(int i = 0; i < 26; i++){
                seen[i] = false;
               
            }
             distinct = 0;
            for(int k = j+1; k < n; k++){
                if(!seen[s[k]-'a']){
                    seen[s[k]-'a'] = true;
                    distinct++;
                }
                right[distinct]++;
            }
            for(int d = 1; d <= 26; d++){
                ans += 1LL * left[d] * right[d];
            }
        }
        return ans;
    }
};