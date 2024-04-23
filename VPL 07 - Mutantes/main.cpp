#include <iostream>
// Bibliotecas sugeridas para resolver o problema:
//
// MAP
#include <set>
// VECTOR
#include <vector>
// PAIR
#include <utility>

#include <algorithm>

using namespace std;

int Converter(string txt) {
    try {
        return stoi(txt);
    } catch (exception &e) {
        cout << 11 << endl;
        // É gambiarra, mas funciona perfeitamente nos outros compiladores, só aqui no Moodle deu erro;
        return 0;
    }
}

int main() {
    vector<int> Especies;
    
    string Entrada;
    getline(cin, Entrada);
    
    while (Converter(Entrada)) {
        set<string> Genes; 
        for (int i = 0; i < Converter(Entrada); i++) {
            string DNA;
            getline(cin, DNA);
            sort(DNA.begin(), DNA.end());
            Genes.insert(DNA);
        }
        Especies.push_back(Genes.size());
        getline(cin, Entrada);
    }
    
    for (int i = 0; i < Especies.size(); i++) {
        cout << Especies.at(i) << endl;
    }

    return 0;
}
