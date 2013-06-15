#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  string side;
  int rail;

  fin >> side;
  fin >> rail;

  if(side == "front" && rail == 1 || side == "back" && rail == 2) {
    fout << "L";
  } else {
    fout << "R";
  }
  return 0;
}
