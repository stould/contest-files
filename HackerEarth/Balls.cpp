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

const int MAXN = 1000005;

int N;
uInt K[MAXN];

int main(void) {
    cin >> N;

    uInt ans = 0;
    set<uInt> st;
    
    for (int i = 0; i < N; i++) {
        uInt u;
        cin >> u;
        st.insert(u);
    }

    for (int i = 0; i < N; i++) {
        uInt goal = (i + 1) * (uInt) (i + 1);

        set<uInt>::iterator it = st.lower_bound(goal - 1);

        if (it == st.end()) {
            it--;
        }
        uInt val = *it;
        
        if (val < goal) {
            ans += goal - val;
        }
        
        st.erase(val);                
    }

    cout << ans <<"\n";
    return 0;
}
