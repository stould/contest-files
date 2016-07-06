#include <bits/stdc++.h>

using namespace std;

int N;
int P[1050];

int main(){
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];

        if (i > 0 && P[i] < P[i - 1]) {
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n";
    return 0;
}
