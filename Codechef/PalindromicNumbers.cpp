#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef long long ll;

string alph = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
ll N, S;

string toBase(ll n, int base) {
    string ans = "";
    while(n > 0) {
        ans = alph[n % base] + ans;
        n /= base;
    }
    return ans;
}

bool isPalindrome(string s) {
    for(int i = 0; i < (int) s.size(); i++) {
        if(s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> S;
        int b = -1;
        for(int j = 2; j <= 26; j++) {
            if(isPalindrome(toBase(S, j))) {
                b = j; break;
            }
        }
        if(b != -1) goto end;
        if(b == -1) {
            ll sqr = (ll) sqrt(S);
            for(ll j = sqr; j >= 2; j--) {
                if(S % j == 0) {
                    b = (ll) S / j - 1;
                }
            }
        }
        if(b == -1) b = S - 1;
        end:;
        cout << b << endl;
    }
    return 0;
}
