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

int T;
string S;

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> S;
        
        vector<int> E;
        map<char, int> mp;
        mp[S[0]] = 1;

        int mx = 2;
        int next = 0;

        E.push_back(1);

        for (int i = 1; i < (int) S.size(); i++) {
            if (mp.find(S[i]) == mp.end()) {
                mp[S[i]] = next;
                if (next == 0) {
                    next = 2;
                } else {
                    next++;
                }
            }
            E.push_back(mp[S[i]]);

            mx = max(mx, E.back() + 1);
        }

        uInt ans = 0;
        
        for (int i = 0; i < (int) E.size(); i++) {
            int val = E[i];
            
            ans = ans * mx + val;
        }

        cout << ans << endl;
    }
    return 0;
}
