#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <iostream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <utility>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

int n;
string possiblesBin[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
string possiblesHex[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};

int strToInt(string s) {
    int ans = 0, base = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        ans += (s[i]-'0') * pow(10, base++);
    }
    return ans;
}

string intToStr(int n) {
    string ans = "";
    if(n == 0) return "0";
    while(n > 0) {
        ans += (char) ((n % 10) + '0');
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int binToDec(string bin) {
	int ret = 0;
	int i = 0;
	while (i < bin.size() && (bin[i] == '0' || bin[i] == '1')) {
		if(bin[i] == '0') {
			ret <<= 1;
		} else {
			ret ^= 1;
			ret <<= 1;
		}
		i++;
	}
	ret >>= 1;
	return ret;
}

int hexToDec(string hex) {
	int n = hex.size() - 1;
	int ret = 0;
	for (int i = 0; i < hex.size(); i++) {
		if (hex[i] >= 'a' && hex[i] <= 'f') {
			ret += (hex[i] - ('a') + 10) * (pow(16, n--));
		} else {
			ret += ((hex[i] - '0') * (pow(16, n--)));
		}
	}
	return ret;
}

string decToOthers(string _value, int toBase) {
	int value = strToInt(_value);
	string ret = "";
	while (value > 0) {
		int aux = (value % toBase);
		if(aux > 9) {
			ret += (char) ((('a' - 9) + aux - 1));
		} else {
			ret += (aux + '0');
		}
		value /= toBase;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int i;
string value, base;

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        printf("Case %d:\n", i + 1);
        cin >> value >> base;
        if(base == "bin") {
            printf("%d dec\n%s hex\n", binToDec(value), decToOthers(intToStr(binToDec(value)), 16).c_str());
        } else if(base == "dec") {
            printf("%s hex\n%s bin\n", decToOthers(value, 16).c_str(), decToOthers(value, 2).c_str());
        } else {
            printf("%d dec\n%s bin\n", hexToDec(value), decToOthers(intToStr(hexToDec(value)), 2).c_str());
        }
        printf("\n");
    }
    return 0;
}

