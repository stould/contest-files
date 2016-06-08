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

string S;

int main(void) {
    cin >> S;

    int N = (int) S.size();

    for (int len = 1; len <= 17; len++) {
        set<int> st;

        for (int i = 0; i + len - 1 < N; i++) {
            int now = 0;
            
            for (int j = 0; j < len; j++) {
                if (S[i + j] == '1') {
                    now |= (1 << j);
                }
            }

            st.insert(now);
        }

        //cout << len << " " << st.size() << "\n";
        
        if (1 << len != (int) st.size()) {
            cout << len << "\n";
            break;
        }
    }    
    
    return 0;
}
