class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int lastA = -1;
        int lastB = -1;
        int lastInvalid = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a'){
                lastA = i;
            }
            else if(s[i] == 'b' && lastA != -1){
                lastB = lastA;
            }
            else if(s[i] == 'c' && lastB != -1){
                lastInvalid = lastB;
            }
            ans += i - lastInvalid;
        }
        return ans;
    }
};