#include <bits/stdc++.h>

using namespace std;

string S;
priority_queue<int> SM;
priority_queue<int, vector<int>, greater<int> > GT;

void balance() {
    while (abs(SM.size() - GT.size()) > 1) {
        if (SM.size() > GT.size()) {
            int tmp = SM.top();
            SM.pop();
            GT.push(tmp);
        } else {
            int tmp = GT.top();
            GT.pop();
            SM.push(tmp);
        }
    }
}

void removeMedian() {
    if (SM.size() == GT.size()) {
        if (SM.top() >= GT.top()) {
            SM.pop();
        } else {
            GT.pop();
        }
    } else {
        if (SM.size() > GT.size()) {
            SM.pop();
        } else {
            GT.pop();
        }
    }
  
    balance();
}

int getMedian() {
    int ans = 0;

    if (SM.empty() && GT.empty()) return 0;
  
    if (GT.size() > 0 && SM.size() > 0) {
        //cout << SM.top() << " " << GT.top() << "\n";
        //cout << SM.size() << " " << GT.size() << "\n";
    }
    if (SM.size() == GT.size()) {
        if (SM.top() >= GT.top()) {
            ans = SM.top();
        } else {
            ans = GT.top();
        }
    } else {
        if (SM.size() > GT.size()) {
            ans = SM.top();
        } else {
            ans = GT.top();
        }
    }
  
    balance();
  
    return ans;
}

void add(int arg) {
    if (arg <= getMedian()) {
        SM.push(arg);
    } else {
        GT.push(arg);
    }

    balance();
}

int main() {
    while (cin >> S) {
        //cout << "S " << getMedian() << "\n";
        if (S == "#") {
            cout << getMedian() << "\n";
            removeMedian();
        } else {
            add(stoi(S));
        }
    }
    return 0;
}
