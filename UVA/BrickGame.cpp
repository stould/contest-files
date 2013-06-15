#include <iostream>
#include <algorithm>

using namespace std;

int T, N, v[15];

int main(void) {
    cin >> T;
    for(int x = 1; x <= T; x++) {
        cin >> N; int ans;
        for(int i = 0; i < N; i++) {
            cin >> v[i];
        }
        for(int i = 0; i < N; i++) {
            int r = 0, l = 0;
            for(int j = 0; j < N; j++) if(i != j) {
                if(v[i] > v[j]) r++;
                if(v[i] < v[j]) l++;
            }
            if(r == l) {
                ans = i;
            }
        }
        cout << "Case " << x << ": " << (v[ans]) << endl;
    }
    return 0;
}
