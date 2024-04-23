#include <iostream>
#include <sstream>

// Bibliotecas sugeridas para resolver o problema:
//
// MAP
#include <map>
// VECTOR
#include <vector>
// PAIR
#include <utility>

using namespace std;

int main() {
    int Entradas;
    
    string Linha;
    getline(cin, Linha);
    stringstream s(Linha);
    
    map<pair<int,int>,int> Senha;

    s >> Entradas;

    for (int i = 0; i < Entradas; i++) {
        map<char,vector<int>> Cadeias;
        vector<int> Numeros;
        vector<char> Letras;
        

        getline(cin, Linha);
        stringstream s(Linha);
        for (int j = 1; j <= Linha.size(); j += 2) {
            string Caractere;
            s >> Caractere;
            if (int(Caractere[0]) < int('A')) {
                Numeros.push_back(stoi(Caractere));
            } else {
                Letras.push_back(Caractere[0]);
            }
        }
        
        for (int l = char('A'), n = 0; l <= char('E'); l++, n+=2) {
            Cadeias[char(l)].push_back(Numeros[n]);
            Cadeias[char(l)].push_back(Numeros[n+1]);
        }
        
        for (int l = 0; l < Letras.size(); l++) {
            for(int n = 0; n < Cadeias[Letras[l]].size(); n++) {
                int num = Cadeias[Letras[l]][n];
                if (Senha[pair<int,int>(l, num)]) {
                    Senha[pair<int,int>(l, num)]++;
                } else {
                    Senha[pair<int,int>(l, num)] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < 6; i++) {
        for(int j = 0; j <= 9; j++) {
            if (Senha[pair<int,int>(i,j)] == Entradas) {
                cout << j << " ";
                break;
            }
        }
    }
    
    return 0;
}
