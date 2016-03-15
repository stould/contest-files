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

const int MAXN = 100010;

int N;
int P[MAXN];
bool used[MAXN];

int main(void) {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    cin >> N;

    srand(time(NULL));

    vector<int> vm;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        if (P[i] == 0) continue;

        bool ok = true;

        int j = i + 1;

        while (P[j] >= P[j - 1]) {
            j += 1;
        }
        
        if (ok) {
            vm.push_back(i);
        }

        i = j - 1;
    }

    Int all = 100101001100101010LL;

    for (int i = 0; i < min((int) vm.size(), 250); i++) {
        int pos = vm[rand() % vm.size()];
        memset(used, false, sizeof(used));
    
        Int ans = 0;
        int ad = 0;
        int init = pos;
        
        while (ad < N) {
            int fit = 0;
            int curr = init;
            int base = curr;
            Int dst = 0;
            
            while (fit < P[base]) {
                if (!used[curr]) {
                    fit += 1;
                    ans += dst * (Int) dst;
                    used[curr] = true;
                }
                dst += 1;
                curr = (curr + 1) % N;
            }

            ad += P[base];
            
            init = (init + 1) % N;
        }
        chmin(all, ans);
        //cout << pos << " " << P[pos] << " " << ans << "\n";
    }
    cout << all << "\n";
    return 0;
}

