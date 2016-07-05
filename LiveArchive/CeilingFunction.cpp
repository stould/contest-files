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

const int MAXN = 1048579;

int N, K;
int P[MAXN];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    //gen(); return 0;
    while (cin >> N >> K) {
        set<vector<int> > st;
        
        for (int i = 0; i < N; i++) {
            vector<int> tree(MAXN, -1);
            vector<int> used(MAXN, -1);
            
            for (int j = 0; j < K; j++) {
                cin >> P[j];
                
                int rt = 1;
                
                while (tree[rt] != -1) {
                    if (tree[rt] > P[j]) {
                        rt = rt * 2;
                    } else {
                        rt = rt * 2 + 1;
                    }
                }
                tree[rt] = P[j];
                used[rt] = 1;
            }
            
            st.insert(used);
        }
        
        cout << st.size() << "\n";
    }
        return 0;
}
