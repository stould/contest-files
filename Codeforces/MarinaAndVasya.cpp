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

int N, T;
string A, B;

int main(void) {
    cin >> N >> T >> A >> B;

    vector<int> df, eq;

    string ans = "";

    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != A[i] && c != B[i]) {
                    ans += c;
                    break;
                }
            }
            df.push_back(i);
        } else {
            ans += A[i];
            eq.push_back(i);
        }
    }

    int IA = (int) df.size();
    int IB = (int) df.size();

    while (!df.empty() && IA > T) {
        int pos = df.back();
        df.pop_back();
        ans[pos] = A[pos];
        IA -= 1;
    }

    while (!df.empty() && IB > T) {
        int pos = df.back();
        df.pop_back();        
        ans[pos] = B[pos];
        IB -= 1;
    }

    if (IA != IB) {
        cout << "-1\n";
    } else {
        while (!eq.empty() && (IA < T && IB < T)) {
            int pos = eq.back();
            eq.pop_back();

            for (char c = 'a'; c <= 'z'; c++) {
                if (ans[pos] != c) {
                    ans[pos] = c;
                    break;
                }
            }
            IA += 1;
            IB += 1;
        }

        if (IA == T && IB == T) {
            cout << ans << "\n";
        } else {
            cout << "-1\n";
        }
    }
    
    return 0;
}
