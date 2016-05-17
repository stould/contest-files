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

string P[5];
string AV[6] = {"AA", "AO", "BB", "BO", "AB", "OO"};

int wayParent(string pa, string pb, string son) {
    int ans = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (pa[i] == son[0] && pb[j] == son[1]) {
                ans += 1;
            }
            if (pa[i] == son[1] && pb[j] == son[0]) {
                ans += 1;
            }
        }
    }

    return ans;
}


int ways(string value, int id) {
    int ans = 0;

    vector<string> sa;   
    vector<string> sb;

    if (P[id].size() == 2) {
        sa.push_back(P[0]);
    } else {
        sa.push_back(P[id] + "O");
        if (P[id] != "O") {
            sa.push_back(P[id] + P[id]);
        }
    }
    
    id++;

    if (P[id].size() == 2) {
        sb.push_back(P[0]);
    } else {
        sb.push_back(P[id] + "O");
        if (P[id] != "O") {
            sb.push_back(P[id] + P[id]);
        }
    }

    for (int i = 0; i < (int) sa.size(); i++) {
        for (int j = 0; j < (int) sb.size(); j++) {
            ans += wayParent(sa[i], sb[j], value);
            if (i < (int) sb.size() && j < (int) sa.size()) {
                //ans += wayParent(sb[i], sa[j], value);
            }
        }
    }

    return ans;
}

int main(void) {
    for (int i = 0; i < 4; i++) {
        cin >> P[i];
    }

    double all = 0.0;
    map<string, int> cnt;

    cout <<"AO " << ways("AO", 0) << endl;
    
    for (int i = 0; i < 6; i++) {        
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                if (wayParent(AV[j], AV[k], AV[i]) > 0) {
                    int inc = ways(AV[j], 0) * ways(AV[k], 2) + ways(AV[j], 2) * ways(AV[k], 0);
                    if (AV[i] == "AA" || AV[i] == "AO") { 
                        //cout << AV[i] << " " << AV[j] << " " << AV[k] << " => " << inc << "\n";
                    }
                    if (inc > 0) {
                        //cout << AV[i] << " = " << AV[j] << " " << AV[k] << " => " << inc << "\n";
                    }
                    
                    all += inc;

                    cnt[AV[i]] += inc;
                }
            }
        }
    }

    double A = (cnt["AA"] + cnt["AO"]) / all;
    double B = (cnt["BB"] + cnt["BO"]) / all;
    double C = (cnt["AB"]            ) / all;
    double D = (cnt["OO"]            ) / all;

    cout << fixed << setprecision(2) << A << " " << B << " " << C << " " << D << "\n";
    
    return 0;
}
