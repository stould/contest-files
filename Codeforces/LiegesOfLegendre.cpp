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

const int MAXN = 100005;

int N, K;
int P[MAXN];

int grundy(int x) {
    if (x <= 1) return x;

    int ans = 0;

    set<int> gr;

    gr.insert(grundy(x - 1));

    if (x % 2 == 0) {
        if (K % 2 == 0) {
            gr.insert(0);
        } else {
            gr.insert(grundy(x / 2));
        }
    }

    while (gr.count(ans)) {
        ans += 1;
    }
    
    return ans;
}

int realGrundy(int x) {
    if (x <= 0) {
        return x;
    } else {
        if (x <= 1) {
            return x;
        }

        if (K % 2 == 0) {
            if (x == 2) {
                return 2;
            } else {
                return 1 - x % 2;
            }
        } else {
            if (x == 2) {
                return 0;
            } else if (x == 3) {
                return 1;
            } else {
                if (x % 2 == 1) {
                    return 0;
                } else {
                    int cnt = 0;
                    
                    while (x % 2 == 0) {
                        cnt += 1;
                        x /= 2;
                    }
                    
                    if (cnt % 2 == 1) {
                        return x == 3 ? 2 : 1;
                    } else {
                        return x % 2 == 1 && x != 3 ? 2 : 1;
                    }
                }
            }
        }
    }
}

int main(void) {
    cin >> N >> K;
    
     for (int i = 0; i <= 10; i++) {
         cout << i << " " << grundy(i) << " " << realGrundy(i) << endl;
     }
    

    int x = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        x ^= realGrundy(P[i]);
    }

    if (x) {
        cout << "Kevin" << endl;
    } else {
        cout << "Nicky" << endl;
    }
    
    return 0;
}
