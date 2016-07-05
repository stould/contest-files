#include <bits/stdc++.h>

using namespace std;

int N, Q;
int l, r;

pair<int, int> isWin(int x, int len) {
    if (x < l) {
        return make_pair(0, len);
    } else {
        int best = -1;
        int other_best = -1;

        for (int i = l; i <= r; i++) {
            pair<int, int> now = isWin(x - i, len + 1);
      
            if (now.first == 0) {
                best = max(best, now.second);
            } else {
                other_best = max(other_best, now.second);
            }
        }
        if (best != -1) {
            return make_pair(1, best);
        } else {
            return make_pair(0, other_best);
        }
    }
}

int main() {
    /*
      l = 1;
      r = 1;

      for (int i = 1; i <= 20; i++) {
      pair<int, int> c = isWin(i, 0);
    
      cout << i << " " << c.first << " " << c.second << "\n";
      }
    */
    cin >> N >> Q;

    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;

        int spent = 0;

        if (N >= A) {
            spent += 1;

            spent += N / (A + B);

            if (N % (A + B) < A) {
                spent += N / (A + B) - 1;
            } else {
                spent += N / (A + B);
            }
        }
        cout << spent << "\n";
    }
    return 0;
}
