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

const int MAXN = 3000005;

int N;
vector<int> tree[MAXN];

int main(void) {
    cin >> N;

    for (int i = 2; i <= N; i++) {
        int P;

        cin >> P;

        tree[i].push_back(P);
        tree[P].push_back(i);
    }

    int root = 1;

    for (int i = 1; i <= N; i++) {
        if (tree[i].size() == 1) {
            root = i;
            break;
        }
    }
    
    vector<int> ans;
    ans.push_back(1);

    for (int i = 2; i < N; i++) {
        if (N % i == 0) {
            
        }
    }
    
    ans.push_back(N);

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
