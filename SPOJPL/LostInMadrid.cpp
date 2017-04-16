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

const int MAXN = 310;
const double EPS = 1e-9;
    
int N;
int P[MAXN][MAXN];
int deg[MAXN];

vector<double> gauss(vector< vector<double> > A) {
    int n = A.size();

    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (fabs(A[k][i]) > maxEl) {
                maxEl = fabs(A[k][i]);
                maxRow = k;
            }
        }
        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n);

    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        if (isnan(x[i])) {
            x[i] = 0;
        }
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}


int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    while (cin >> N && N != 0) {
        int A, B;

        memset(P, 0, sizeof(P));
        memset(deg, 0, sizeof(deg));
        
        for (int i = 0; i < N; i++) {
            cin >> A >> B;

            P[A][B] = P[B][A] = 1;

            deg[A] += 1;
            deg[B] += 1;
        }

        vector<vector<double> > M(300, vector<double>(302, 0));
        
        for (int i = 0; i < 300; i++) {
            M[i][i] = 1;
        }
        for (int i = 0; i <= 290; i++) {
            if (P[i][300]) {
                M[i][300] = (1.0 / (double) deg[i]);
            }
            
            for (int j = 0; j <= 300; j++) {
                if (j > 290 && j < 300) continue;
                
                if (P[i][j]) {
                    M[i][j] = -(1.0 / (double) deg[i]);
                }
            }
        }
        vector<double> ans = gauss(M);

        double a = fabs(ans[0]);

        if (isnan(a)) a = 0;
        
        cout << fixed << setprecision(3) << a + EPS << endl;
    }
    return 0;
}
