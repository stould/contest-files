#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    vector<int> v;

    int n, t;

    scanf("%d", &n);

    while(n > 0) {
        scanf("%d", &t);
        v.push_back(t);
        n--;
    }

    for(t = 0; t < v.size() - 1; t++) {
        if(v[t] < v[t + 1]) {
            int temp = v[t];
            v[t] = v[t + 1];
            v[t + 1] = temp;
        }
    }

    for(t = 0; t < v.size(); t++) {
        printf("%d\n", v[t]);
    }
    return 0;
}
