/**
 * Uma loja online deseja analisar o histórico de vendas de um determinado produto para melhorar sua
 * estratégia de marketing. O objetivo é identificar o período de tempo em que o aumento nas vendas
 * foi o maior possível. Dado um array de inteiros representando as vendas diárias de um produto,
 * encontre a subsequência contígua de maior variação nas vendas e determine seu valor.
 *
 * Entrada: A primeira linha contém um único inteiro N (2 <= N <= 10^5), representando o número de
 * dias. A segunda linha contém N inteiros A[i] (0 <= A[i] <= 10^4), representando as vendas diárias do
 * produto.
 *
 * Saída: Imprima um único inteiro, que representa o valor da maior variação nas vendas em um
 * período contíguo.
 *
 * Exemplo de Entrada:
 * 7
 * 3 4 7 1 2 6 9
 * Exemplo de Saída:
 * 8
 * Explicação: A maior variação é entre 1 e 9 (dias 4 e 7), com uma variação de 8
 */

#include <cstddef>
#include <iostream>
#include <vector>

int main()
{
   const std::vector<int> vendasDia{3, 4, 7, 1, 2, 6, 9}; // número de dias: 2 <= N <= 10^5

   int variacaoAtual{vendasDia[1] - vendasDia[0]};
   int maiorVariacao{variacaoAtual};
   for (std::size_t i{1}, j{2}; j < vendasDia.size(); ++i, ++j)
   {
      int variacaoEntreDoisDias{vendasDia[j] - vendasDia[i]};

      // algoritmo de Kadane
      variacaoAtual += variacaoEntreDoisDias;
      if (variacaoAtual < variacaoEntreDoisDias)
      {
         variacaoAtual = variacaoEntreDoisDias;
      }
      if (maiorVariacao < variacaoAtual)
      {
         maiorVariacao = variacaoAtual;
      }
   }

   std::cout << maiorVariacao << '\n';

   return 0;
}
