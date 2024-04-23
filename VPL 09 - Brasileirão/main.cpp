#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <functional>
#include <map>          // std::map
#include <set>
#include <queue>        // std::priority_queue
#include <sstream>
#include <utility>      // std::pair
#include <cctype>       // std::tolower
#include <algorithm>    // std::sort
#include <vector>

using namespace std;

class Times {
    private:
        string _nome;
        
        int _posicao;
        double _pontos;
        double _numjogos;
        int _golspos;
        int _golscontra;
        int _saldo;
        
    public:
        Times(string nome) {
            this->_nome       = nome;
            this->_pontos     = 0;
            this->_numjogos   = 0;
            this->_golspos    = 0;
            this->_golscontra = 0;
        }
    
        string getNome() const {
            return this->_nome;
        }

        int getPontos() const {
            return this->_pontos;
        }

        int getJogos() {
            return this->_numjogos;
        }

        int getGolsPos() const {
            return this->_golspos;
        }

        int getGolsContra() {
            return this->_golscontra;
        }

        int getSaldo() const {
            return this->_golspos - this->_golscontra;
        }
        
        float getAproveitamento() {
            return (this->_pontos/(3*this->_numjogos)) * 100;
        }

        void adicionaPontos(int pontos) {
            this->_pontos += pontos;
            this->_numjogos++;
        }

        void adicionaGols(int gols) {
            if (gols > 0) {
                this->_golspos += gols;
            } else {
                this->_golscontra += -gols;
            }
            this->_saldo = this->_golspos - this->_golscontra;
        }

        bool operator==(const Times& time) const {
            if (this->getPontos() == time.getPontos() && this->getSaldo() == time.getSaldo() && this->getGolsPos() == time.getGolsPos()) {
                return true;
            }
            return false;
        }

        bool operator<(const Times& time) const {
            if (this->getPontos() == time.getPontos()) {
                if (this->getSaldo() == time.getSaldo()) {
                    if (this->getGolsPos() == time.getGolsPos()) {
                        string nome1 = this->getNome();
                        string nome2 = time.getNome();
                        transform(nome1.begin(), nome1.end(), nome1.begin(), [](unsigned char c) {
                            return std::toupper(c);
                        });
                        transform(nome2.begin(), nome2.end(), nome2.begin(), [](unsigned char c) {
                            return std::toupper(c);
                        });
                        return lexicographical_compare(nome2.begin(), nome2.end(), nome1.begin(), nome1.end());
                    } else {
                        return this->getGolsPos() < time.getGolsPos();
                    }
                } else {
                    return this->getSaldo() < time.getSaldo();
                }
            } else {
                return this->getPontos() < time.getPontos();
            }
        }
};

bool timesComparator(const Times* left, const Times* right) {
    return *right < *left;
}

class Tabela {
    private:
        map<string, Times*> _tabela;
        multiset<Times*, bool(*)(const Times*, const Times*)> _ordenar{timesComparator};
    public:
        Tabela() {}
    
        void adicionaTime(Times *time) {
            this->_tabela[time->getNome()] = time;
        }
        
        void computaJogo(string time1, int gols1, int gols2, string time2) {
            if (gols1 > gols2) {
                this->_tabela[time1]->adicionaPontos(3);
                this->_tabela[time2]->adicionaPontos(0);
            } else if(gols1 == gols2) {
                this->_tabela[time1]->adicionaPontos(1);
                this->_tabela[time2]->adicionaPontos(1);
            } else {
                this->_tabela[time1]->adicionaPontos(0);
                this->_tabela[time2]->adicionaPontos(3);
            }

            this->_tabela[time1]->adicionaGols( gols1);
            this->_tabela[time1]->adicionaGols(-gols2);
            this->_tabela[time2]->adicionaGols(-gols1);
            this->_tabela[time2]->adicionaGols( gols2);
        }

        void imprime() {
            int i = 0;
            Times* anterior = nullptr;

            for (const auto &t : this->_tabela) {
                this->_ordenar.insert(t.second);
            }

            for (const auto &t : this->_ordenar) {
                i++;
                if (anterior == nullptr || !(*t == *anterior)) {
                    cout << setw(3) << i << ".";
                } else {
                    cout << setw(4) << " ";
                }
                cout << setw(16) << t->getNome();
                cout << setw(4) << t->getPontos();
                cout << setw(4) << t->getJogos();
                cout << setw(4) << t->getGolsPos();
                cout << setw(4) << t->getGolsContra();
                cout << setw(4) << t->getSaldo();
                if (t->getJogos() != 0) {
                    cout << setw(7) << fixed << setprecision(2) << t->getAproveitamento();
                } else {
                    cout << setw(7) << "N/A";
                }
                cout << endl;
                anterior = t;
            }
        }
};

int main() {
    string nomeTime;
    string time1, time2, ignore;
    int gols1, gols2;
    int numTimes, numJogos;
    
    Tabela* Brasileirao = new Tabela();
    
    cin >> numTimes;
    cin >> numJogos;
    
    for (int i = 0; i < numTimes; i++) {
        cin >> nomeTime;
        Times* novoTime = new Times(nomeTime);
        Brasileirao->adicionaTime(novoTime);
    }
    
    for (int i = 0; i < numJogos; i++) {
        cin >> time1 >> gols1 >> ignore >> gols2 >> time2;
        Brasileirao->computaJogo(time1, gols1, gols2, time2);
    }

    Brasileirao->imprime();
    
    return 0;
}
