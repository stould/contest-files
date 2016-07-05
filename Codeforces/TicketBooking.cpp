#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int N, M, K;
int A[MAXN], B[MAXN];

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    int pa = 0;

    vector<vector<int> > all;

    for (int i = 0; i < M; i++) {
        if (pa >= N) break;

        if (A[pa] == B[i]) {
            int cnt = 0;
            vector<int> vs;

            while (pa < N && cnt + 1 <= K && A[pa] == B[i]) {
                vs.push_back(pa + 1);
                cnt += 1;
                pa += 1;
                i++;
            }
            i -= 1;

            all.push_back(vs);
        }
    }

    cout << all.size() << "\n";

    for (int i = 0; i < (int) all.size(); i++) {
        cout << all[i].size() << " ";
        for (int j = 0; j < all[i].size(); j++) {
            cout << all[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
