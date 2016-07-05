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

int N;

int func(int x, int k) {
    vector<int> vs(x);
    for (int i = 0; i < x; i++) {
        vs[i] = i;
    }
    int pos = 0;
    for (int i = 0; i < x - 1; i++) {
        int next;

        if (i % 2 == 0) {
            next = (pos + k - 1) % ((int) vs.size());
        } else {
            next = (pos - k + 1) % ((int) vs.size());
            next += (int) vs.size();
            next %= (int) vs.size();
        }
        vs.erase(vs.begin() + next);
        cout << vs[next] + 1 << "\n";
        pos = next;
    }
    return vs[0] + 1;
}

int main(void) {
    func(5, 1);
    /*
    while (cin >> N && N != 0) {
        for (int i = 1; i <= 10; i++) {
            cout << i << " " << func(5, i) << "\n";
            if (func(100, i) == N) {
             
                break;
            }
        }
    }
    */
    return 0;
}
