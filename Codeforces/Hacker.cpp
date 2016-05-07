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
int A[MAXN], B[MAXN];
int V[MAXN];

int main(void) {
    while (cin >> N && N != 0) {
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        
        map<int, int> check;

        for (int i = 0; i < N; i++) {
            check[B[i]] = i + 1;
        }

        int vpos = 0;
        
        for (int i = 0; i < N; i++) {
            if (check[A[i]] > 0) {
                V[vpos++] = check[A[i]];
            }
        }

        set<int> s;
        set<int>::iterator it;

        for (int i = 0; i < vpos; i++) {            
            s.insert(V[i]);
            
            it = s.upper_bound(V[i]);
            
            if(it != s.end()) {
                s.erase(it);
            }
        }

        cout << s.size() << "\n";
    }
    return 0;
}
