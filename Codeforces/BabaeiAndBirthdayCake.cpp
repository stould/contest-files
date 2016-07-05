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
const double PI = acos(-1);
const double EPS = 1e-7;

int N;
int R[MAXN], H[MAXN];

int main(void) {
    cin >> N;

    multiset<double> st;
    
    for (int i = 0; i < N; i++) {
        cin >> R[i] >> H[i];

        double volume = PI * R[i] * R[i] * H[i];

        
        multiset<double>::iterator it = st.lower_bound(volume);
        /*set<double>::iterator it = st.begin();
          
        while (it != st.end()) {
            if (*it >= volume) {
                it--;
                break;
            }
            it++;
        }
        if (!st.empty() && it == st.end()) {
            it--;
        }
        */
        cout << volume << endl;
        
        if (it != st.end()) {
            cout << volume << " " << *it << "\n";
            if (*it + EPS < volume) {
                st.insert(volume + *it);
            }
        } else {
            cout << "none\n";
        }
        
        st.insert(volume);
    }

    double ans = *st.rbegin();

    cout << fixed << setprecision(7) << ans << "\n";
    
    return 0;
}
