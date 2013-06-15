#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    bool ok = true;

    cin >> N;
    vector<int> message(N);

    for(int i = 0; i <= N; i++) {
        cin >> message[i];
    }

    cout << "A";
    for(int i = 0; i < N; i++) {
        if(message[i] == '1') {
            for(int j = i; j < N; j *= 2) {
                if(message[j] != '1') {
                    for(int k = j; k < N; k++) {
                        if(message[k] == '1') {
                            ok = false;
                        }
                    }
                } else {
                    continue;
                }
             }
        }
    }
    if(ok) cout << "YES"; else cout << "NO";
    return 0;
}
