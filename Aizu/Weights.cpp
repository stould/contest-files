#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <stdio.h>

using namespace std;

int v[] = {512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
int w;
stack<int> spent;

int main(void) {
    while(~scanf("%d", &w)) {
        for(int i = 0; i < 10; i++) {
            if(w >= v[i]) {
                w -= v[i];
                spent.push(v[i]);
            }
        }
        while(!spent.empty()) {
            if(spent.size() == 1) {
                cout << spent.top();
            } else {
                cout << spent.top() << " ";
            }
            spent.pop();
        }
        cout << endl;
    }
    return 0;
}
