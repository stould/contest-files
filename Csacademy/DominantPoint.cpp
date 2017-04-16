#include <cstdio>
#include <iostream>

using namespace std;

int N;
int X[100005];
int Y[100005];

int main() {
    cin >> N;
    
    int bx = -1;
    int by = -1;
    
    int id = -1;
    int cnt = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        
        bx = max(bx, X[i]);
        by = max(by, Y[i]);
    }
    for (int i = 0; i < N; i++) {
        if (X[i] == bx && Y[i] == by) {
            cnt += 1;
            id = i + 1;
        }
    }
    if (cnt == 1) {
        cout << id << "\n";
    } else {
        cout << "-1\n";
    }
}
