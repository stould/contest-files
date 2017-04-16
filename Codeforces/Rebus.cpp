#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

string S;

vector<string> split(string& arg) {
    istringstream ss(arg);
    string buff;
    vector<string> ans;

    while (ss >> buff) {
        ans.push_back(buff);
    }
    
    return ans;
}

int eval(vector<string> arg) {
    int ans = stoi(arg[0]);
    
    for (int i = 2; i < (int) arg.size() - 1; i++) {
        if (arg[i] == "=") break;
        
        if (arg[i - 1] == "+") {
            ans += stoi(arg[i]);
        } else if (arg[i - 1] == "-") {
            ans -= stoi(arg[i]);
        }
    }

    return ans;
}

int main(void) {
    getline(cin, S);

    vector<string> sp = split(S);
    
    int N = stoi(sp.back());

    
    
    return 0;
}
