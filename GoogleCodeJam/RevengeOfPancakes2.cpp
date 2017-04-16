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

const int INF = INT_MAX / 4;

int T;
string S;
map<int, int> memo;
map<int, int> seen;

bool ok(string& arg) {
    for (int i = 0; i < (int) arg.size(); i++) {
        if (arg[i] == '-') {
            return false;
        }
    }
    return true;
}

string rev(string arg, int id) {
    string cpy = arg;
    
    for (int i = id; i >= 0; i--) {
        if (cpy[i] == '+') {
            cpy[i] = '-';
        } else {
            cpy[i] = '+';
        }
    }

    for (int i = 0; i <= id / 2; i++) {
        swap(cpy[i], cpy[id - i]);
    }

    //cout << "deb " << arg << " " << cpy << " " << id << endl;
    
    return cpy;
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> S;

        int N = (int) S.size();
        int ans = 0;

        string now = S;
            
        for (int i = N - 1; i >= 0; i--) {
            if (now[i] == '-') {
                if (now[0] == '+') {
                    for (int j = i - 1; j >= 0; j--) {
                        string next = rev(now, j);
                        
                        next = rev(next, i);
                        
                        if (next[i] == '+') {
                            now = next;
                            ans += 2;
                            break;
                        }
                    }                    
                } else {
                    string next = rev(now, i);
                    
                    if (next[i] == '+') {
                        ans += 1;
                        now = next;
                    }                        
                }
            }
        }
        
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}
