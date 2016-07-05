#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 40010;

const uInt BASE = 7883ULL;
const uInt C_BASE = 4549ULL;

int N;
string S;
uInt hsh[MAXN];
uInt pwd[MAXN];
uInt cmp[MAXN];

void build(const string& arg) {
    hsh[0] = 0ULL;
    pwd[0] = 1ULL;
    cmp[0] = 1ULL;

    for (int i = 1; i <= (int) arg.size(); i++) {
        hsh[i] = hsh[i - 1] * BASE + (arg[i - 1] - 'a');
        pwd[i] = pwd[i - 1] * BASE;
        //        cmp[i] = cmp[i - 1] * BASE;
    }
}

uInt getHash(int l, int r) {
    return hsh[r] - hsh[l] * pwd[r - l] + cmp[r - l];
}

int main(void) {
    while (cin >> N && N != 0) {
        cin >> S;        

        build(S);

        int ans = 0, pos = 0;
        int l = 1, h = (int) S.size(), m;

        while (l <= h) {
            m = (l + h) / 2;

            unordered_map<uInt, int> cnt;
            int r_most = 0;

            bool ok = false;

            for (int i = 0; i + m <= (int) S.size(); i++) {
                uInt c_hash = getHash(i, i + m);

                cnt[c_hash] += 1;

                if (cnt[c_hash] >= N) {
                    ok = true;
                    r_most = i;
                }
            }

            if (ok) {
                ans = m;
                pos = r_most;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        if (ans > 0) {
            cout << ans << " " << pos << "\n";
        } else {
            cout << "none\n";
        }
    }
    return 0;
}
