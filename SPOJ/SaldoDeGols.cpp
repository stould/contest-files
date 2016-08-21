#include <iostream>
 
using namespace std;
 
int partidas, favor, contra, teste = 1;
 
int main(void) {
    while(1) {
        cin >> partidas;
        if (!partidas) break;
 
        cout << "Teste " << teste << endl;
 
        int best = -1, best_from, best_to, from = 1, soma = 0;
 
        for(int partida = 1 ; partida <= partidas; partida ++) {
            int favor, contra;
            cin >> favor >> contra;
            soma += favor - contra;
            if (soma < 0) {
                from = partida + 1;
                soma = 0;
            } else if (soma > 0 && (soma > best || (soma == best && partida-from >= best_to-best_from))) {
                best = soma;
                best_from = from;
                best_to = partida;
            }
        }
        if(best == -1) {
            cout << "nenhum" << endl;
        } else {
            cout << best_from << " " << best_to << endl;
        }
        cout << endl;
        teste ++;
    }
    return 0;
}
 
 
