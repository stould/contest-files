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

bool vowel(char c) {
    string v = "aeiouy";

    if (v.find(c) != string::npos) return true;
    return false;
}

int main(void) {
    cin >> S;

    string A = "";
    string B = "";

    for (int i = 0; i < (int) S.size(); i++) {
        if (vowel(S[i])) {
            A += S[i];
        } else {
            B += S[i];
        }
    }
    
    if (A > B) {        
        cout << "Vowel\n";
    } else {
        cout << "Consonant\n";
    }
    return 0;
}
