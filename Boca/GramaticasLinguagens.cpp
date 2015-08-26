#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <math.h>
#include <string.h>
#define MAXN 2001
#define INF 500000000
#define ll long long

using namespace std;

int n;

bool dig(char x){
    return x >= '0' && x <= '9';
}

bool upp(char x){
    return x >= 'A' && x <= 'Z';
}

bool low(char x){
    return x >= 'a' && x <= 'z';
}

bool tipo3(string pre, string con){
    if(pre.size() == 1){
        if(!upp(pre[0])){
            return 0;
        }else{
            if(con.size() == 1){
                return dig(con[0]) || low(con[0]) || con[0] == '#';
            }else if(con.size() == 2){
                return (dig(con[0]) || low(con[0])) && upp(con[1]);
            }else{
                return 0;
            }
        }
    }else{
        return 0;
    }
}

bool tipo2(string pre, string con){
    if(pre.size() == 1){
        if(!upp(pre[0])){
            return 0;
        }else{
            if(con.size() == 1){
                return con[0] == '#' || dig(con[0]) || low(con[0]) || upp(con[0]);;
            }else{
                for(int i = 0; i < con.size(); i++){
                    bool ok = dig(con[i]) || low(con[i]) || upp(con[i]);
                    if(!ok) return 0;
                }
                return 1;
            }
        }
    }else{
        return 0;
    }
}

bool tipo1(string pre, string con){
    if(pre.size() > con.size()){
        return 0;
    }else{
        int vars = 0;
        for(int i = 0; i < pre.size(); i++){
            for(int i = 0; i <  pre.size(); i++){
                bool ok = dig( pre[i]) || low( pre[i]) || upp( pre[i]);
                if(!ok) {
                    return 0;
                }
                vars += upp(pre[i]);
            }
        }
        if(vars == 0){
            return 0;
        }else{
            return 1;
        }
    }
}

string par[2][21];

int main(void){
    //freopen("in.in", "r", stdin);
    while(cin >> n && n){
        for(int i = 0; i < n; i++){
            cin >> par[0][i];
            cin >> par[1][i];
            par[0][i] = par[0][i].substr(1,par[0][i].size()-2);
            par[1][i] = par[1][i].substr(0,par[1][i].size()-1);
        }
        bool t3 = 1;
        for(int i = 0; i < n; i++){
            if(!tipo3(par[0][i], par[1][i])){
                t3 = 0;
                break;
            }
        }
        if(t3){
            cout << "Tipo 3" << endl;
            continue;
        }
        bool t2 = 1;
        for(int i = 0; i < n; i++){
            if(!tipo2(par[0][i], par[1][i])){
                t2 = 0;
                break;
            }
        }
        if(t2){
            cout << "Tipo 2" << endl;
            continue;
        }
        bool t1 = 1;
        for(int i = 0; i < n; i++){
            if(!tipo1(par[0][i], par[1][i])){
                t1 = 0;
                break;
            }
        }
        if(t1){
            int cnt = 0, idx = -1;
            for(int i = 0; i < n; i++){
                if(par[1][i].size() == 1 && par[1][i][0] == '#'){
                    cnt++;
                    idx = i;
                }
            }
            if(cnt > 1){
                t1 = 0;
            }else if(cnt == 1 && idx != 0){
                t1 = 0;
            }else if(cnt == 1 && par[0][idx].size() > 1){
                t1 = 0;
            }else if(cnt == 1 && !upp(par[0][idx][0])){
                t1 = 0;
            }else{
                if(cnt == 1){
                    char V = par[0][idx][0];
                    for(int i = 0; i < n; i++){
                        for(int j = 0; j < par[1][i].size(); j++){
                            if(par[1][i][j] == V) t1 = 0;
                        }
                    }
                }
            }
            if(t1){
                cout << "Tipo 1" << endl;
                continue;
            }
        }
        cout << "Tipo 0" << endl;
    }
    return 0;
}

