#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct aluno {
    string nome;
    int rank, soma;

    aluno(){}

    aluno(string _nome, int _n) {
        nome = _nome;
        soma = _n;
    }

    bool operator<(const aluno& a) const {
        if(soma == a.soma) {
            return nome < a.nome;
        }
        return soma > a.soma;
    }
};

string nome, s;
int i, n, tmp, t = 1;

int main(void) {
  //  freopen("i.in", "r", stdin);
    while(cin >> n && n > 0) {
        vector<aluno> an;
        for(i = 0; i < n; i++) {
            int ma = -100000, mi = 1000000, sum = 0;
            cin >> nome;
            cin.ignore();
            getline(cin, s);

            stringstream ss(s);

            while(ss >> tmp) {
                sum += tmp;
                ma = max(ma, tmp);
                mi = min(mi, tmp);
            }
            sum = sum - ma - mi;
            an.push_back(aluno(nome, sum));
        }
        sort(an.begin(), an.end());
        an[0].rank = 1;
        for(i = 1; i < an.size(); i++) {
            if(an[i].soma == an[i - 1].soma) {
                an[i].rank = an[i - 1].rank;
            } else {
                an[i].rank = i + 1;
            }
        }
        cout << "Teste " << t++ << endl;
        for(i = 0; i < an.size(); i++) {
            cout << an[i].rank << " " << an[i].soma << " " << an[i].nome << endl;
        }
        cout << endl;
    }
    return 0;
}
