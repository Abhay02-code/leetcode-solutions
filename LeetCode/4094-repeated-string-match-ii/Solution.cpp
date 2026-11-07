class Solution {
public:
    bool repeatedStringMatch(string a, string b, int x, int y) {
        long long n = a.size();
        long long m = b.size();

        long long lenA = n * x;
        long long lenB = m * y;

        if(lenB > lenA){
            return false;
        }

        long long maxStart = lenA - lenB;

        long long g = gcd(n,m);
        long long limit = n+m-g;
        long long check = min(lenB, limit);
        for(long long start = 0; start < n && start <= maxStart; start++){
            bool valid = true;
            for(long long j = 0; j < check; j++){
                if(a[(start+j)%n] != b[j%m]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                return true;
            }
        }
        return false;
        
    }
};