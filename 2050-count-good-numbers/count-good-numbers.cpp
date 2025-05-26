class Solution {
public:
    const int MOD = 1000000007;

    // Function for modular exponentiation: (base^exp) % mod
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;  // Count of positions needing even digits
        long long oddPositions = n / 2;         // Count of positions needing prime digits
        
        return (modPow(5, evenPositions, MOD) * modPow(4, oddPositions, MOD)) % MOD;
    }
};
