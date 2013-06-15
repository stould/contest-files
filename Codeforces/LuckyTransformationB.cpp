#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    int i, n, k, temp;
    string cs;
    vector<int> v;

    scanf("%d %d", &n, &k);

    getline(cin, cs);
    getline(cin, cs);

    for(i = 0; i < n; i++) {
        v.push_back(cs[i] - '0');
    }

    while(k > 0) {
        for(i = 0; i < n - 1; i++) {
            if(v[i] == 4 && v[i + 1] == 7) {
                if((i + 1) % 2 != 0) {
                    v[i] = v[i + 1] = 4;
                } else {
                    v[i] = v[i + 1] = 7;
                }
                break;
            }
        }
        if(n == n- 2) {
            break;
        }
        k--;
    }

    for(i = 0; i < v.size(); i++) { cout << v[i]; }

    return 0;
}
