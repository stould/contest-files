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

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const Int MAX_V = 1000000000000000000LL;

int N;
vector<int> buff;
unordered_map<Int, int> dp[100005];

bool func(Int level, Int val) {
    //cout << level << " " << val <<"\n";
    if (level == N + 1) {
        //cout << "OK\n";
        return 1;
    } else {
        if (dp[level].find(val) == dp[level].end()) {
            dp[level][val] = 0;
        
            for (Int st = level + 1; st <= 10000000; st += 10) {
                Int df = st * st - val;
                
                if (df >= 0 && df % level == 0 && st % (level + 1) == 0) {
                    int ok = func(level + 1, st);
                    
                    if (ok) {
                        buff.push_back(df / level);
                        dp[level][val] = 1;
                        break;
                    }
                }
            }
        }
        return dp[level][val];
    }
}


int main(void) {
    cin >> N;


    func(1, 2);

    for (int i = (int) buff.size() - 1; i >= 0; i--) {
        cout << buff[i] << "\n";
    }
    
    return 0;
}
