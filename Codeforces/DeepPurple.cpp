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

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 200005;
int N, Q;
string S;

uInt C1 = 0;
uInt B1 = 2;
//uInt C1 = 5831ULL;
//uInt B1 = 991ULL;

uInt C2 = 523ULL;
uInt B2 = 617ULL;

uInt C[MAXN][2];
uInt poww[MAXN][2];
uInt h[MAXN][2][2];

void pre() {
    poww[0][0] = 1ULL;
    poww[0][1] = 1ULL;

    C[0][0] = C1;
    C[0][1] = C2;
  
    for (int i = 1; i < MAXN; i++) {
        poww[i][0] = poww[i-1][0] * B1;
        poww[i][1] = poww[i-1][1] * B2;

        C[i][0] = C[i-1][0] * C1;
        C[i][1] = C[i-1][1] * C2;
    }
}

void buildHash(string& arg, int id) {
    h[0][id][0] = 0ULL;
    h[0][id][1] = 0ULL; 

    for (int i = 1; i <= (int) arg.size(); i++) {
        h[i][id][0] = h[i - 1][id][0] * B1 + (arg[i - 1]);
        h[i][id][1] = h[i - 1][id][1] * B2 + (arg[i - 1]);
    }
}

pair<uInt, uInt> getHash(int id, int a, int b){
    uInt ha = h[b][id][0] - h[a][id][0] * poww[b-a][0] + C[b-a][0];
    uInt hb = h[b][id][1] - h[a][id][1] * poww[b-a][1] + C[b-a][1];

    return make_pair(ha, hb);
}

int main(void) {
    cin >> N >> Q >> S;

    string SR = S; 
    reverse(SR.begin(), SR.end());
    
    buildHash(S, 0);
    buildHash(SR, 1);
    
    for ( ; Q--; ) {
        int a, b;
        cin >> a >> b;

        a -= 1;
        b -= 1;

        int l = 1, h = b - a + 1;
        int ans = 0;

        while (l <= h) {
            int m = (l + h) / 2;
            
            //pair<uInt, uInt> pl = getHash(0, a, a + m);
            //pair<uInt, uInt> pr = getHash(1, N - (a + m), N - a);

            //cout << hash<
            //cout << pl.first << " " << pr.first << endl;
            //cout << S.substr(a, m) << " " << SR.substr(N - (a + m), m) << endl;

            hash<string> sh;

            string sa = S.substr(a, m);
            string sb = S.substr(b - m + 1, m);
            string sc = sb;
            
            reverse(sb.begin(), sb.end());
            //cout << sh(S.substr(a, m)) << " " <<  sh(SR.substr(N - (a + m), m)) << "\n";
            //cout << S.substr(a, m) << " " << SR.substr(N - (a + m), m) << endl;
            cout << sa << " " << sb << "\n";
            if (sh(sa) == sh(sb)) {
                if (sa == sc) {
                    ans = m;
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            } else {
                h = m - 1;
            }
        }
        
        cout << max(0, ans - 1) << endl;
    }
    
    return 0;
}
