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

const double EPS = 1e-8;
const double PI  = acos(-1);

int N;
int X[6], Y[6];
int P[6];

double len(int a, int b) {
    return sqrt((X[a] - X[b]) * (X[a] - X[b]) + (Y[a] - Y[b]) * (Y[a] - Y[b]));
}

double dot(int a, int b, int c) {
    return (X[a] - X[b]) * (X[c] - X[b]) + (Y[a] - Y[b]) * (Y[c] - Y[b]);
}

double angle(int i, int j, int k) {
    //cout << dot(i, j, k) << "\n";

    if (fabs(len(i, j) * len(j, k)) < EPS) return 0;
    //cout << fixed << setprecision(10) << dot(i, j, k) << " " << (len(i, j) * len(j, k)) << " => " << acos(dot(i, j, k) / (len(i, j) * len(j, k))) * 180 / PI << "\n";
    return acos(dot(i, j, k) / (len(i, j) * len(j, k))) * 180 / PI;
}


int main(void) {
    N = 5;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        P[i] = i;
    }

    do {
        set<Int> dst;
        double agl = 0.0;
        
        for (int i = 0; i < 5; i++) {
            int pi = P[i];
            int pj = (P[i + 1] % N);
            int pk = (P[i + 2] % N);
            
            agl += angle(pi, pj, pk);            
        }
        if (agl > 400) {
            cout << fixed << setprecision(2) << agl << "\n";
        }
    } while (next_permutation(P, P + N));
    return 0;
}
