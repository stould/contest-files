#include <bits/stdc++.h>

using namespace std;

const int MAXN = 32;

int T, N, M;
int P[MAXN][MAXN];
int ans;
pair<int, int> pans;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool spand(int a, int b, int len) {
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j < 4; j++) {
            int da = a + dx[j] * i;
            int db = b + dy[j] * i;
            if (da >= 0 && db >= 0 && da < N && db < M) {
                if (P[da][db] <= 0) {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    return true;
}

void use(int a, int b, int len) {
    P[a][b]--;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < 4; j++) {
            int da = a + dx[j] * i;
            int db = b + dy[j] * i;
            P[da][db] -= 1;
        }
    }
}

void deuse(int a, int b, int len) {
    P[a][b]++;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < 4; j++) {
            int da = a + dx[j] * i;
            int db = b + dy[j] * i;
            P[da][db] += 1;
        }
    }
}



void rec(int r, int c, int cnt, pair<int, int> pa) {
    if (r >= N) {
        if (cnt >= ans) {
            bool go = 1;
            for(int i = 0; i < N && go; i++){
                for(int j = 0; j < M && go; j++){
                    if(P[i][j] == 1) go = 0;
                }
            }
            if(go){
                ans = cnt;
                pans = max(pans, pa);
            }
        }  
    } else if (c >= M) {
        rec(r + 1, 0, cnt, pa);
    } else {   
        if (r > 0 && c > 0 && r < N - 1 && c < M - 1 && P[r][c] == 1 ) {
            for (int i = 1; i <= 5; i++) {	
                if (spand(r, c, i)) {
                    if (cnt + 1 <= 9) {
                        use(r, c, i);
                        rec(r, c + 1, cnt + 1, max(pa, make_pair(r, c)));
                        deuse(r, c, i);
                    }
                } else {
                    break;
                }
            }
        }
        rec(r, c + 1, cnt, pa);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> P[i][j];
            }
        }

        pans = make_pair(-1, -1);
        ans = 0;

        rec(0, 0, 0, make_pair(-1, -1));

        cout << ans << "\n";
        cout << pans.first + 1 << " " << pans.second + 1<< "\n";
    }
    return 0;
}
