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
typedef unsigned uint;

const double EPS = 1e-9;
const double MAX_VAL = 100000000000.0;

const int MAX_ITER = 1000;

double M[3][3];

bool eq(double a, double b) {
    return fabs(a - b) < EPS;
}

double A() {
    double ans = MAX_VAL;
    double l = 0.0, h = ans, m;

    for (int x = 0; x < MAX_ITER; x++) {
        m = (l + h) / 2;
        double shold = m;
		
        double v = (M[0][0] + shold) * (M[1][1] + shold) - (M[0][1] - shold) * (M[1][0] - shold);


        if (eq(v, 0)) {
            chmin(ans, abs(M[0][0] - (M[0][0] + shold)));
            chmin(ans, abs(M[1][1] - (M[1][1] + shold)));
            chmin(ans, abs(M[0][1] - (M[0][1] - shold)));
            chmin(ans, abs(M[1][0] - (M[1][0] - shold)));
        } else if (v < 0) {
            l = m;
        } else {
            h = m;
        }
    }
    return ans;
}

double B() {
    double ans = MAX_VAL;
    double l = 0.0, h = ans, m;

    for (int x = 0; x < MAX_ITER; x++) {
        m = (l + h) / 2;
        double shold = m;
        
        double v = (M[0][0] - shold) * (M[1][1] - shold) - (M[0][1] + shold) * (M[1][0] + shold);

        if (eq(v, 0)) {
            chmin(ans, abs(M[0][0] - (M[0][0] - shold)));
            chmin(ans, abs(M[1][1] - (M[1][1] - shold)));
            chmin(ans, abs(M[0][1] - (M[0][1] + shold)));
            chmin(ans, abs(M[1][0] - (M[1][0] + shold)));
        } else if (v > 0) {
            l = m;
        } else {
            h = m;
        }
    }
    return ans;
}

double C() {
    double ans = MAX_VAL;
    double l = 0.0, h = ans, m;

    for (int x = 0; x < MAX_ITER; x++) {
        m = (l + h) / 2;
        double shold = m;
        
        double v = (M[0][0] + shold) * (M[1][1] + shold) - (M[0][1] - shold) * (M[1][0] - shold);

        if (eq(v, 0)) {
            chmin(ans, abs(M[0][0] - (M[0][0] + shold)));
            chmin(ans, abs(M[1][1] - (M[1][1] + shold)));
            chmin(ans, abs(M[0][1] - (M[0][1] - shold)));
            chmin(ans, abs(M[1][0] - (M[1][0] - shold)));
        } else if (v > 0) {
            l = m;
        } else {
            h = m;
        }
    }
    return ans;
}

double D() {
    double ans = MAX_VAL;
    double l = 0.0, h = ans, m;

    for (int x = 0; x < MAX_ITER; x++) {
        m = (l + h) / 2;
        double shold = m;
        
        double v = (M[0][0] - shold) * (M[1][1] - shold) - (M[0][1] + shold) * (M[1][0] + shold);

        if (eq(v, 0)) {
            chmin(ans, abs(M[0][0] - (M[0][0] - shold)));
            chmin(ans, abs(M[1][1] - (M[1][1] - shold)));
            chmin(ans, abs(M[0][1] - (M[0][1] + shold)));
            chmin(ans, abs(M[1][0] - (M[1][0] + shold)));
        } else if (v < 0) {
            l = m;
        } else {
            h = m;
        }
    }
    return ans;
}


int main(void) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> M[i][j];
        }
    }
    
    cout << fixed << setprecision(9) << min(A(), min(B(), min(C(), D()))) << "\n";
    
    return 0;
}
