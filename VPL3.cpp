#include<iostream>

using namespace std;

typedef struct Categoria{
  int _codigo_categoria;
  double _valor_caixa;

} Categoria;

// Inicializa um objeto categoria com seu código e o valor que ela deve ter em caixa para gastos com sua pasta.
void inicia_categoria(Categoria *categoria, int codigo_categoria, double valor_caixa) {
  categoria->_codigo_categoria = codigo_categoria;
  categoria->_valor_caixa = valor_caixa;
}

// Recupera o código correspondente a uma categoria.
int codigo_categoria(Categoria *categoria) {
  return categoria->_codigo_categoria;
}

// Recupera o valor em caixa de uma categoria.
double valor_caixa_categoria(Categoria *categoria){
  return categoria->_valor_caixa;
}

// Adiciona uma quantia ao caixa de uma categoria.
void adiciona_caixa_categoria(Categoria *categoria, double valor) {
  categoria->_valor_caixa += valor;
}

// Remove uma quantia ao caixa de uma categoria.
void gasta_caixa_categoria(Categoria *categoria, double valor) {
  categoria->_valor_caixa -= valor;
}


typedef struct Orcamento {
  double _impostos;
  Categoria _saude, 
            _educacao, 
            _seguranca, 
            _previdencia, 
            _administracao;
  
  // Preencher
} Orcamento;

// Inicializa um objeto Orçamento, sendo que ele deve conter um objeto categoria para cada pasta.
// Recebe como parâmetro o valor monetário que deve ser atribuído a aquele orçamento.
// Este valor deve ser distribuído a cada categoria, nos percentuais descritos anteriormente.
void inicia_orcamento(Orcamento *orcamento, double impostos) {
  orcamento->_impostos = impostos;
  inicia_categoria(&orcamento->_saude, 0, impostos*0.15);
  inicia_categoria(&orcamento->_educacao, 1, impostos*0.15);
  inicia_categoria(&orcamento->_seguranca, 2, impostos*0.2);
  inicia_categoria(&orcamento->_previdencia, 3, impostos*0.35);
  inicia_categoria(&orcamento->_administracao, 4, impostos*0.15);
  cout << "initiated" << endl;
}

// Reduz o valor no caixa da categoria especificada.
void gasto_categoria(Orcamento *orcamento, int codigo_categoria, double valor) {
  switch (codigo_categoria) {
    case 0:
      gasta_caixa_categoria(&orcamento->_saude, valor);
      break;
    case 1:
      gasta_caixa_categoria(&orcamento->_educacao, valor);
      break;
    case 2:
      gasta_caixa_categoria(&orcamento->_seguranca, valor);
      break;
    case 3:
      gasta_caixa_categoria(&orcamento->_previdencia, valor);
      break;
    case 4:
      gasta_caixa_categoria(&orcamento->_administracao, valor);
      break;
    default: break;
  }
}

// Retorna o valor em caixa da categoria especificada.
double saldo_categoria(Orcamento *orcamento, int codigo_categoria) {
  switch (codigo_categoria) {
    case 0:
      return valor_caixa_categoria(&orcamento->_saude);
      break;
    case 1:
      return valor_caixa_categoria(&orcamento->_educacao);
      break;
    case 2:
      return valor_caixa_categoria(&orcamento->_seguranca);
      break;
    case 3:
      return valor_caixa_categoria(&orcamento->_previdencia);
      break;
    case 4:
      return valor_caixa_categoria(&orcamento->_administracao);
      break;
    default: 
      break;
  }
  return 0;
}

// Retorna o ponteiro para o objeto da categoria especificada.
Categoria* recupera_categoria(Orcamento *orcamento, int codigo_categoria) {
  switch (codigo_categoria) {
    case 0:
      return &orcamento->_saude;
      break;
    case 1:
      return &orcamento->_educacao;
      break;
    case 2:
      return &orcamento->_seguranca;
      break;
    case 3:
      return &orcamento->_previdencia;
      break;
    case 4:
      return &orcamento->_administracao;
      break;
  }
}

int main() {
  Orcamento orcamento;  

  char test = 0;
  while(cin >> test) {
  switch (test) {
    case 'o': {
      double valor = 0;
      cin >> valor;
      inicia_orcamento(&orcamento, valor);
    }
    break;
    case 'g': {
      int categoria = 0;
      double valor = 0;
      cin >> categoria >> valor;
      gasto_categoria(&orcamento, categoria, valor);
      cout << categoria << ": " << saldo_categoria(&orcamento, categoria) << endl;
    }
    break;
    case 'p': {
      for (int categoria = 0; categoria < 5; categoria++) {
        cout << categoria << ": " << saldo_categoria(&orcamento, categoria) << endl;
      }
    }
    break;
    default: {
      cout << "----------" << endl;
    } break;
  }
  }
  return 0;
}
