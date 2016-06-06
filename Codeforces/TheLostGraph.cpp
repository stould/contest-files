#include <bits/stdc++.h>

using namespace std;

int N, id;
string S;
int main() {
    cin >> N;

    stack<int> stk;  

    for (int i = 0; i < 2 * N; i++) {
        cin >> S >> id;

        if (S == "in") {
            stk.push(id);
        } else {
            if (!stk.empty()) {
                stk.pop();
            }
            if (!stk.empty()) {
                cout << id << " " << stk.top() << "\n";
	
                //stk.pop();
            }
        }
    }
    return 0;
}
