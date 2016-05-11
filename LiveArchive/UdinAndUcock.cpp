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
Int N;

int main(void) {
    set<int> st;

    st.insert(4);
    st.insert(8);
    st.insert(14);
    st.insert(20);
    st.insert(24);
    st.insert(28);
    st.insert(34);
    st.insert(38);

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        cout << "Case #" << t << ": ";
        if (N < 42) {
            if (st.count(N)) {
                cout << "UCOK" << endl;
            } else {
                cout << "UDIN" << endl;
            }
        } else {
            N -= 42;
            N %= 34;

            //cout << N << endl;
            
            vector<int> poss;
            
            poss.push_back(0);
            poss.push_back(12);
            poss.push_back(4);
            poss.push_back(4);
            poss.push_back(10);
            poss.push_back(4);

            int cnt = 0;
            bool ok = false;
        
            for (int i = 0; i < (int) poss.size(); i++) {
                cnt += poss[i];

                if (N == cnt) {
                    ok = true;
                }
            }
            if (ok) {
                cout << "UCOK" << endl;
            } else {
                cout << "UDIN" << endl;
            }
        }
    }
    /*    
          memset(dp, -1, sizeof(dp));

          vector<int> ps;
    
          for (int i = 42; i <= 200; i++) {
          if (getNim(i) == 0) {
          ps.push_back(i);
          cout << i << " " << getNim(i) << endl;
          }
          }
          for (int i = 1; i < ps.size(); i++) {
          cout << ps[i] - ps[i - 1] << endl;
          }

          int P = 190;

          cout << (P - 42) % 32 << endl;
    */
    return 0;
}
