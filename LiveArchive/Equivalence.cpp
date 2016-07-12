#include <bits/stdc++.h>
using namespace std;

typedef long long Int;

int T;
string ss1, ss2, s1, s2;
map<char, char> mp;

//Solver for mathematical expressions
void doOp(stack<Int> &num, stack<char> &op){
    Int A = num.top(); num.pop();
    Int B = num.top(); num.pop();
    char oper = op.top(); op.pop();
    Int ans;
    if(oper == '+'){
        ans = A+B;
    }else if(oper == '-'){
        ans = B-A;
    }else if(oper == '*'){
        ans = A*B;
    }else{
        if(A != 0){
            ans = B/A;
        }else{
            //division by 0
            ans = -1;
        }
    }
    num.push(ans);
}
 
Int parse(string s){
    stack<char> op;
    stack<Int> num;
    map<char,Int> pr;

    //setting the priorities, greater values with higher pr
    pr['+'] = 0;
    pr['-'] = 0;
    pr['*'] = 1;
    pr['/'] = 1;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == ')'){
            while(!op.empty() && op.top() != '('){
                doOp(num,op);
            }
            op.pop();
        } else if(s[i] == '('){
            op.push('(');
        } else if(!(s[i] >= '0' && s[i] <= '9')){
            while(!op.empty() && pr[s[i]] <= pr[op.top()] && op.top() != '('){
                doOp(num,op);
            }
            op.push(s[i]);
        } else {
            Int ans = 0;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                ans = ans * 10 + (s[i] - '0');
                i++;
            }
            i--;
            num.push(ans);
        }
    }
    while (op.size()) {
        doOp(num,op);
    }
    return num.top();
}

int main(void) {

    for(char c='a'; c<='z'; c++) {
        mp[c] = '1';
    }
  
    cin >> T;
    cin.ignore();
    while(T--) {

        getline(cin, ss1);
        getline(cin, ss2);

        bool ans = true;
        int sz1 = ss1.size(), sz2 = ss2.size();
        s1 = "";
        s2 = "";
    
        string vals = "+-*()";

        for(int i=0; i<sz1; i++) {
            if (ss1[i] == ' ' || ss1[i] == '\t') continue;
            if (isalnum(ss1[i]) || vals.find(ss1[i]) != string::npos) {
                s1 += tolower(ss1[i]);
            }
        }
        for(int i=0; i<sz2; i++) {
            if (ss2[i] == ' ' || ss2[i] == '\t') continue;
            if (isalnum(ss2[i]) || vals.find(ss2[i]) != string::npos) {
                s2 += tolower(ss2[i]);
            }
        }
    
        sz1 = s1.size();
        sz2 = s2.size();

        for(char c='a'; c <= 'z'; c++) {
            mp[c] = '9';
            string a1 = s1, a2 = s2;
            for(int i=0; i<sz1; i++) {
                if(a1[i] >= 'a' && a1[i] <= 'z')
                    a1[i] = mp[a1[i]];
            }
            for(int i=0; i<sz2; i++) {
                if(a2[i] >= 'a' && a2[i] <= 'z')
                    a2[i] = mp[a2[i]];
            }
            //cout << parse(a1) << " " << parse(a2) << "\n";
            if(parse(a1) != parse(a2)) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
