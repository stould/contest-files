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

const long double EPS = 1e-25;

int N;
string S;

int main(void) {
    cin >> N >> S;
    
    long double M = 0.5;
    long double T = 0.5;

    long double SM = 0.0;
    long double ST = 0.0;

    for (int i = 0; i < N; i++) {        
        T /= 2.0;
        M /= 2.0;
        
        ST += T;
        SM += M;
        
        if (S[i] == 'H') {
            T += 0.5;           
        } else {
            M += 0.5;
        }
        
        cout << ST << " " << SM <<endl;
    }
    //cout << T << " " << M << endl;
    if (fabs(ST - SM) < EPS) {
        cout << "HM" << endl;
    } else {    
        if (ST > SM) {
            cout << "H" << endl;
        } else {
            cout << "M" << endl;
        }
    }
    return 0;
}
