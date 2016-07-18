#include <iostream>
#include <algorithm>
#include <stdio.h>
 
using namespace std;
 
struct aluno {
    string nome;
    int problem;
 
    aluno() {}
    aluno(string _nome, int _problem) {
        nome = _nome;
        problem = _problem;
    }
    bool operator<(const aluno& a) const {
        if(problem == a.problem) {
            return nome > a.nome;
        }
        return problem < a.problem;
    }
};
 
int i, t, n, test = 1;
char tmp[60];
aluno mem[110];
 
int main(void) {
    while(~scanf("%d", &n)) {
        for(i = 0; i < n; i++) {
            scanf("%s %d", tmp, &t);
            mem[i].nome = string(tmp);
            mem[i].problem = t;
        }
        sort(mem, mem + n);
        cout << "Instancia " << (test++) << endl;
        cout << mem[0].nome << endl << endl;
    }
    return 0;
}
