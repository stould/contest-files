//Accepted
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

typedef long long Int;
typedef unsigned uint;
typedef unsigned long long uInt;

const int MAXN = 50050;
const uInt MOD_A = 1000000007ULL;
const uInt MOD_B = 1000000009ULL;

const uInt BASE_A = 29ULL;
const uInt BASE_B = 31ULL;

int T;
string S;
uInt hA[MAXN], hB[MAXN], pA[MAXN], pB[MAXN];

uInt modPow(uInt a, uInt n, uInt mod) {
    uInt res = 1ULL;
	
    while (n > 0ULL) {
        if (n & 1) {
            res = (res * a) % mod;
        }
        a = (a * 1ULL * a) % mod;
        n >>= 1;
    }
	
    return res;
}

uInt inv(uInt x, uInt mod) {
    return modPow(x, mod - 2, mod);
}


void hashFunc(string s) {
    int N = (int) s.size();

    memset(hA, 0, sizeof(hA));
    memset(hB, 0, sizeof(hB));

    pA[0] = pB[0] = 1LL;

    for (int i = 0; i < N; i++) {
        if (i > 0) {
            pA[i] = (pA[i - 1] * BASE_A) % MOD_A;
            pB[i] = (pB[i - 1] * BASE_B) % MOD_B;

            hA[i] = hA[i - 1];
            hB[i] = hB[i - 1];
        } 

        int val = S[i] - 'A' + 1;

        hA[i] = (hA[i] + (pA[i] * (val) % MOD_A) % MOD_A)  % MOD_A;
        hB[i] = (hB[i] + (pB[i] * (val) % MOD_B) % MOD_B)  % MOD_B;
    }
}

pair<uInt, uInt>  hashL(int l, int r) {
    uInt ans_a = hA[r];
    uInt ans_b = hB[r];
	
    if (l > 0) {
        ans_a -= hA[l - 1];
        ans_b -= hB[l - 1];
    }
	
    ans_a = (ans_a + MOD_A) % MOD_A;
    ans_b = (ans_b + MOD_B) % MOD_B;

    if (l > 0) {
        ans_a = (ans_a  * (inv(pA[l], MOD_A) % MOD_A)) % MOD_A;
        ans_b = (ans_b  * (inv(pB[l], MOD_B) % MOD_B)) % MOD_B;
    }

    return make_pair(ans_a, ans_b);
}

void gen(void) {
    freopen("i.in", "w", stdout);
    int t = 100;
    cout << t << endl;
    srand(time(NULL));
    for (int x = 0; x < t; x++) {
        int len = rand() % 50000;
        for (int j = 0; j < len; j++) {
            cout << char('A' + (rand() % 25));
        }
        cout << endl;
    }	
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> S;

        hashFunc(S);

        int ans = 0;
        int N = (int) S.size();
		
        int L = 0, R = N - 1;
        int pL = 0, pR = N - 1;
		
        bool reach = false;
		
        for ( ; L < R; ) {
            //			cout << S.substr(pL, L - pL + 1) << " " << hashL(pL, L).first << " " << S.substr(R, pR - R + 1) << " " << hashL(R, pR).first << "\n";
            pair<uInt, uInt> ha = hashL(pL, L);
            pair<uInt, uInt> hb = hashL(R, pR);

            if (ha.first == hb.first && ha.second == hb.second) {
                ans += 2;
                pL = L + 1;
                pR = R - 1;

                if (L + 1 == R) {
                    reach = true;
                }
            }
            L += 1;
            R -= 1;
        }

        if (!reach) ans += 1;
		
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
