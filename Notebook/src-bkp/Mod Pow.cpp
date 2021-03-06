//modpow(a, n, mod) - calcula a^n % mod de maneira eficiente
int modpow(int a, int n, int mod) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n /= 2;
    }
    return res;
}

