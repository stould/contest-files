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

typedef __int128 Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int T, N, J;

Int convert(string val, Int base) {
    Int ans = 0;

    Int pw = 1;
    
    for (int i = (int) val.size() - 1; i >= 0; i--) {
        ans += (val[i] - '0') * pw;
        pw *= base;            
    }
    
    return ans;
}

bool isPrime(Int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    Int m = (Int) sqrt(n);

    for (Int i = 3L; i <= m; i += 2L) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> J;

        cout << "Case #" << t << ":" << endl;

        string str = "";
        int cnt = 0;
        
        for (int i = 0; i < N - 2; i++) {
            str += "0";
        }

        str = "1" + str + "1";

        for (int i = 0; i < 1 << (N - 2); i++) {
            for (int j = 1; j < N - 1; j++) {
                if (i & (1 << (j - 1))) {
                    str[j] = '1';
                } else {
                    str[j] = '0';
                }
            }
            
            bool ok = true;
            
            for (int j = 2; j <= 10; j++) {
                Int in_base = convert(str, j);

                if (isPrime(in_base)) {
                    ok = false;
                }
            }

            if (ok) {
                cnt += 1;
                
                cout << str << " ";
                
                for (int j = 2; j <= 10; j++) {
                    Int in_base = convert(str, j);

                    for (int j = 2; j < in_base; j++) {
                        if (in_base % j == 0) {
                            cout << j << " ";
                            break;
                        }
                    }
                }
                
                cout << endl;

                if (cnt == J) {
                    break;
                }
            }
        }
    }
    return 0;
}
