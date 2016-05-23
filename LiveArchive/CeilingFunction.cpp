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

const int MAXN = 2000005;

int N, K;
int P[MAXN];

void gen() {
   srand(time(NULL));
    cout << 50 << " " << 20 << endl;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 20; j++) {
            cout << j << " ";
        }
        cout << endl;
    }    
}

int main(void) {
    //gen(); return 0;
    cin >> N >> K;

    set<vector<int> > st;
    
    for (int i = 0; i < N; i++) {
        vector<int> tree(MAXN, -1);
        
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
        }

        for (int j = 0; j < MAXN; j++) {
            if (tree[j] != -1) {
                tree[j] = 1;
            }
        }

        st.insert(tree);
    }

    cout << st.size() << "\n";
    return 0;
}
