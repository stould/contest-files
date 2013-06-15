#include <iostream>
#include <algorithm>

using namespace std;

int N, v[110];

int main(void) {
    cin >> N;
    int ts = 0;
    for(int i = 0; i < N; i++) cin >> v[i];

    for(int i = 0; i < N; i++) {
        for(int j = N - 1; j >= i + 1; j--) {
			if(v[j] < v[j - 1]) {
				swap(v[j], v[j - 1]); ts += 1;
			}
		}
    }
    for(int i = 0; i < N; i++) {
        if(i == N - 1) {
            cout << v[i] << endl;
        } else {
            cout << v[i] << " ";
        }
    }
    cout << ts << endl;
    return 0;
}
