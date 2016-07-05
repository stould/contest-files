#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;

int N, M;

int main(void) {
    while(cin >> N) {
        vector<int> v(N);
        for(int i = 0; i < N; i++) {
            cin >> v[i];
        }
        cin >> M;
        sort(v.begin(), v.end());
        int a, b, diff = 10000000000;
        for(int i = 0; i < N; i++) {
            if(binary_search(v.begin(), v.end(), M - v[i])) {
                if(fabs((v[i]) - (M - v[i])) < diff) {
                    a = v[i];
                    b = M - v[i];
                    diff = fabs(a - b);
                }
            }
        }
        cout << "Peter should buy books whose prices are " << min(a, b) << " and " << max(a, b) << "." << endl;
        cout << endl;
    }
    return 0;
}
