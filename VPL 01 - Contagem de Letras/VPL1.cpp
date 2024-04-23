#include <iostream>
#include <map>

using namespace std;

int main()
{
  map<char, int> contagem = {};

  string palavra;
  cin >> palavra;

  for (int i = 0; i < palavra.length(); i++) {
    char letra = palavra.at(i);
    if (contagem[letra]) {
      contagem[letra]++;
    } else {
      contagem[letra] = 1;
    }
  }

  for ( const auto &p : contagem )
  {
    cout << p.first << ' ' << p.second << endl;
  } 

  return 0;
}
