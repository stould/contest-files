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

int T;
string S[MAXN];
int V[MAXN];
map<int, int> use;
map<int, Int> getMinMap;

int main(void) {
    cin >> T;

    getMinMap[T] = 10000000000LL;

    for (int i = 0; i < T; i++) {
        cin >> S[i];
        if (S[i] != "removeMin") {
            cin >> V[i];

            use[V[i]] = i + 1;
        }
    }
    for (int i = T - 1; i >= 0; i--) {
        getMinMap[i] = getMinMap[i + 1];
        if (S[i] == "getMin") {
            getMinMap[i] = V[i];
        }
    }

    multiset<int> st;
    vector<pair<string, int> > ans;
    
    for (int i = 0; i < T; i++) {
        if (S[i] == "insert") {
            ans.push_back(make_pair("insert", V[i]));
            st.insert(V[i]);
        } else if (S[i] == "removeMin") {
            if (st.empty()) {
                st.insert(1);
                ans.push_back(make_pair("insert", 1));
            } 
            st.erase(st.begin());        
            ans.push_back(make_pair("removeMin", 0));
        } else if (S[i] == "getMin") {
            while (!st.empty() && *st.begin() < V[i]) {
                ans.push_back(make_pair("removeMin", 0));
                st.erase(st.begin());
            }
            if (st.empty()) {
                st.insert(V[i]);
                ans.push_back(make_pair("insert", V[i]));
            } else {
                if (*st.begin() != V[i]) {
                    st.insert(V[i]);
                    ans.push_back(make_pair("insert", V[i]));
                }
            }
            ans.push_back(make_pair("getMin", V[i]));
        }
    }

    cout << ans.size() << "\n";

    for (int i = 0; i < (int) ans.size(); i++) {
        if (ans[i].first == "removeMin") {
            cout << ans[i].first << "\n";
        } else {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
    return 0;
}
