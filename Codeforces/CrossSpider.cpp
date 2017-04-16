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

const int MAXN = 100005;

int N;
double X[MAXN], Y[MAXN], Z[MAXN];

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
    cin >> N;

    if (N <= 3) {
        cout << "TAK" << endl;
    } else {    
        for (int i = 0; i < N; i++) {
            cin >> X[i] >> Y[i] >> Z[i];
        }
        
        vector<vector<double> > mat(3, vector<double>(5, 0));
        
        for (int i = 0; i < 3; i++) {
            mat[i][0] = X[i];
            mat[i][1] = Y[i];
            mat[i][2] = Z[i];
        }

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < (int) mat[i].size(); j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        vector<double> plane = gauss(mat);

        double plane_x = plane[0];
        double plane_y = plane[1];
        double plane_z = plane[2];
        double plane_d = plane[3];

        cout << plane_x <<" " << plane_y << " " << plane_z << " " << plane_d <<  endl;

        
    }
    return 0;
}
