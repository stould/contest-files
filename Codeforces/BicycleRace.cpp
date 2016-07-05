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

const int MAXN = 1010;

int N;
int X[MAXN], Y[MAXN];
char P[MAXN];

char dir(int a, int b, int x, int y) {
    if (y > b) return 'N';
    if (y < b) return 'S';
    if (x > a) return 'E';
    return 'W';
}

int main(void) {
    cin >> N;

    set<string> se;

    se.insert("EN");
    se.insert("NW");
    se.insert("WS");
    se.insert("SE");
    
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    int ans = 0;
    
    for (int i = 1; i < N; i++) {
        P[i] = dir(X[i - 1], Y[i - 1], X[i], Y[i]);
        //cout << X[i - 1] << " " << Y[i - 1] << " " << X[i] << " " << Y[i] << " " << P[i] << "\n";
    }

    for (int i = 2; i < N; i++) {
        string str = "";

        str += P[i - 1];
        str += P[i];
        
        if (se.count(str)) {
            //cout << X[i - 1] << " " << Y[i - 1] << " " << str << "\n";
            ans += 1;
        }
    }

    cout << ans << "\n";
    
    return 0;
}
