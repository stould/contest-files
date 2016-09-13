#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;
int A[2], B[2];

int main() {
    vector<int> V[2];

    for (int i = 0; i < 2; i++) {
        cin >> A[0] >> B[0] >> A[1] >> B[1];

        for (int j = A[0]; j <= B[0]; j++) {
            for (int k = A[1]; k <= B[1]; k++) {
                V[i].push_back(j + k);
            }
        }
    }
    double all = 0.0;
    double win = 0.0;

    for (int i = 0; i < (int) V[0].size(); i++) {
        for (int j = 0; j < (int) V[1].size(); j++) {
            if (V[0][i] == V[1][j]) continue;
            all += 1;
            if (V[0][i] > V[1][j]) {
                win += 1;
            }
        }
    }
    double pA = win / all;
    double pB = 1 - pA;
    //cout << pA << " " << pB << "\n";
    if (fabs(pA - pB) < EPS) {
        cout << "TIE\n";
    } else {
        if (pA > pB) {
            cout << "Gunnar\n";
        } else {
            cout << "Emma\n";
        }
    }
  
    return 0;
}
