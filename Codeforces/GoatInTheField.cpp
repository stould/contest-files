#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int GX, GY;
string S;
string NM[MAXN];
int N;
int PX[MAXN], PY[MAXN];

int dx = 0;
int dy = 0;

int dist(int a, int b, int p, int q) {
    int ans = 0;

    ans += abs(a - p) / 2;

    if (abs(a - p) % 2 == 1) {
        ans += 1;
    }

    ans += abs(b - q) / 2;

    if (abs(b - q) % 2 == 1) {
        ans += 1;
    }

    return ans;
}

int main(void) {
    cin >> GX >> GY >> S >> N;

    if (S == "LEFT") dx--;
    else if (S == "RIGHT") dx++;
    else if(S == "UP") dy++;
    else dy--;

    for (int i = 0; i < N; i++) {
        cin >> NM[i] >> PX[i] >> PY[i];
    }

    int l = 0, h = 1000000, m;
    string best = "";
    int best_id = 0;

    while (l <= h) {
        m = (l + h) / 2;

        int NGX = GX + m * dx;
        int NGY = GY + m * dy;

        bool found = false;
        int best_ds = INT_MAX;

        for (int i = 0; i < N; i++) {
            int ds = dist(NGX, NGY, PX[i], PY[i]);


            if (ds <= m) {
                found = true;
	
                ds = best_ds;
                best_id = i;
                break;
            }
        }

        if (found) {
            best = NM[best_id];
            h = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << best << "\n";

    return 0;
}
