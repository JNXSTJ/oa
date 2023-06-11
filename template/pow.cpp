
const int MOD = 1e9 + 7;

long pow(long x, int n) {
    long res = 1L;
    for (; n; n /= 2) {
        if (n % 2) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}
