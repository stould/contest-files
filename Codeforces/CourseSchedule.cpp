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

int main(void) {
    cin >> T;

    map<string, set<pair<string, string> > > mp;
    
    for (int i = 0; i < T; i++) {
        string A, B, C;     
        
        cin >> A >> B >> C;

        mp[C].insert(make_pair(A, B));
    }

    for (auto& it : mp) {
        cout << it.first << " " << it.second.size() << endl;
    }
    return 0;
}
