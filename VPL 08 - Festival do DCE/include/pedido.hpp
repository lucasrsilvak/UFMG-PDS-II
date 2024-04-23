#ifndef PEDIDO_H
#define PEDIDO_H

#include <list>

#include "cachorro_quente.hpp"
#include "acai.hpp"
#include "pizza.hpp"
#include "produto.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um pedido.
 */
class Pedido {
 public:
  /**
   * @brief Destrutor da classe.
   * Aqui voce deve deletar os ponteiros contidos na lista _produtos
   */
  ~Pedido();

  /**
   * @brief Adiciona um novo produto ao pedido.
   * @param p Ponteiro do tipo base Produto.
   * Pode ser da classe derivada: Pizza, Hamburguer ou Japonesa.
   */
  void adicionaProduto(Produto* p);

  /**
   * @brief Calcula o valor total do pedido.
   * @return float Valor total do pedido
   */
  float calculaTotal() const;

  /**
   * @brief Retorna um resumo detalhado do pedido, com todos os produtos.
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   * @return std::string Resumo do pedido
   */
  std::string resumo() const;

  /**
   * @brief Atualiza o endereco de entrega
   *
   * @param endereco Endereco de entrega
   */
  void setEndereco(const std::string& endereco);

 private:
  /**
   * @brief Lista de produtos do pedido. Pode ser do tipo Açaí, Pizza
   * ou Cachorro-Quente.
   */
  std::list<Produto*> _produtos;

  /**
   * @brief Endereco de entrega do pedido
   *
   */
  std::string _endereco;
};
#endif