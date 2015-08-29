#include <bits/stdc++.h>

using namespace std;

vector<string> nomes;

int n, pos, walk;

void ajusta(){
  vector<string> newNames(n," ");
  for(int i = 1; i <= n; i++){
    newNames[i%n] = nomes[i-1];
  }
  nomes = newNames;
}


int main() {
  while(cin >> n){
    
    for(int i = 0; i < n; i++){
      nomes.push_back("");
      cin >> nomes[i];
    }
    cin >> walk;
    pos = 0;
    int K = 0, rodadas = 0;
    string last = "";
    while(K+1 < n){
      pos = (pos + walk) % n;
      rodadas++;
      if(nomes[pos] != " "){
	last = nomes[pos];
	nomes[pos] = " ";
	K++;
	if(K < n){
	  ajusta();
	}
      }
    }
    for(int i = 0; i < n; i++){
      if(nomes[i] != " "){
	last = nomes[i];break;
      }
    }
    cout << "apos " << rodadas  << " rodadas quem levou a bolada foi " << last << endl;
   
  }
  return 0;
}
