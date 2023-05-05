/**
 * Dado um vetor de inteiros, remova todos os números múltiplos de 3 e imprima o vetor resultante.
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
   std::vector<int> integers{1, -2, 3, 4, -5, 6, 7, -8, 9, 10, 50, -23, 78, 100, -345};

   auto toEraseIter{std::remove_if(integers.begin(), integers.end(), [](int x) -> bool
                                   { return x % 3 == 0; })};
   integers.erase(toEraseIter, integers.end());

   for (const int integer : integers)
   {
      std::cout << integer << '\t';
   }
   std::cout << '\n';

   return 0;
}