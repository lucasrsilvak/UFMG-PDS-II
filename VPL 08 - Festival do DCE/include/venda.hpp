#ifndef VENDA_H
#define VENDA_H

#include <list>
#include <iomanip> 
#include "pedido.hpp"

/**
 * @brief Esta classe e responsavel pelo gerenciamento dos pedidos.
 * Ela armazenda a lista de pedidos que foram recebidos e imprime um relatorio
 * de vendas.
 */
class Venda {
 public:
  /**
   * @brief Adiciona um novo pedido a lista de pedidos processados.
   * @param p Representa o novo pedido que foi recebido.
   */
  void adicionaPedido(Pedido* p);

  /**
   * @brief Imprime um relatorio de vendas detalhado com todos os pedidos
   * realizados, a quantidade de pedidos recebidos e o total de venda.
   * 
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de vendas e a quantidade
   * de pedidos processados.
   */
  void imprimeRelatorio() const;

  /**
   * @brief Destrutor da classe
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
  ~Venda();

 private:
  /**
   * @brief Lista de pedidos recebidos
   */
  std::list<Pedido*> _pedidos;
};
#endif