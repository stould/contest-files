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

int N;
string P[MAXN];

bool isOk(string x) {
    int zr = 0;
    int on = 0;
    int ot = 0;

    for (int i = 0; i < (int) x.size(); i++) {
        if (x[i] == '0') {
            zr += 1;
        } else if (x[i] == '1') {
            on += 1;
        } else {
            ot += 1;
            break;
        }
    }

    return ot == 0 && on == 1 && zr == (int) x.size() - 1;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
           
    cin >> N;

    bool isZero = false;
    int cntZero = 0;
    string other = "1";
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];

        if (isOk(P[i])) {
            cntZero += P[i].size() - 1;
        } else {
            if (P[i] == "0") {
                isZero = true;
            }
            other = P[i];            
        }
    }

    if (isZero) {
        cout << "0\n";
    } else {
        cout << other;
        
        for (int i = 0; i < cntZero; i++) {
            cout << "0";
        }
        
        cout << "\n";
    }
	return 0;
}
