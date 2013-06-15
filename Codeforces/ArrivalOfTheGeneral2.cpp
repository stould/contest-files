#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int i, j, mi = 10000, mx = -1, ii, ix;

int main(void) {
    int N;
    cin >> N;
    vector<int> v(N);

    for(i = 0; i < N; i++) {
        cin >> v[i];
         if(v[i] <= mi) {
            mi = v[i];
            ii = i;
        }
        if(v[i] >= mx) {
            mx = v[i];
            ix = i;
        }
    }
    int c = 0;
    while((v[0] != mx || (v[N - 1] != mi))) {
        if(ii < N - 1) {
            swap(v[ii], v[ii + 1]);
            ii++;
            c++;
        }
        for(i = 0; i < N; i++) cout << v[i] << " ";
        cout << endl;
        if(ii == ix) {
        if(ix > 0) {
            swap(v[ix], v[ix - 1]);
            ix--;
            c++;
        }
        if(ix > 0) {
            swap(v[ix], v[ix - 1]);
            ix--;
            c++;
        }
        } else {
        if(ix > 0) {
            swap(v[ix], v[ix - 1]);
            ix--;
            c++;
        }
        }
        for(i = 0; i < N; i++) cout << v[i] << " ";
        cout << endl;
    }
    cout << c << endl;
    return 0;
}
