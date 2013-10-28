    #include <cstdio>
    #include <climits>
    #include <cstring>

    int i, j, x;
    int n, m, c[30], dp[1000010];

    inline void fastRead_int(int &x) {
        register int c = getchar_unlocked();

        x = 0;

        int neg = 0;

        for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

        if (c=='-') {
            neg = 1;
            c = getchar_unlocked();
        }

        for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
            x = (x<<1) + (x<<3) + c - 48;
        }

        if (neg) {
            x = -x;
        }
    }

    int main(void) {
        fastRead_int(x);
        for( ; x-->0; ) {
            fastRead_int(n);
            fastRead_int(m);
            for(i = 0; i < n; i++) {
                fastRead_int(c[i]);
                dp[i] = INT_MAX / 2;
            }
            for (i = n; i <= m; i++) dp[i] = INT_MAX / 2;
            dp[0] = 0; dp[1] = 1;
            for(i = 2; i <= m; i++) {
                for(j = n - 1; j >= 0; j--) if (i - c[j] >= 0) {
                    int& now = dp[i];
                    int next = dp[i - c[j]] + 1;

                    if(next < now) {
                        now = next;
                    }
                }
            }
            printf("%d\n", dp[m]);
        }
        return 0;
    }
