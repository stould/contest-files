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

int N, M;
unordered_map<int, bool> seen;

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int tp;
        cin >> tp;

        seen[tp] = true;
    }

    vector<int> ans;

    for (int i = 1; i <= 200000; i++) {
        if (!seen[i]) {
            if (M - i < 0) {
                break;
            }
            ans.push_back(i);
            M -= i;            
        }
    }

    cout << ans.size() << "\n";

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
