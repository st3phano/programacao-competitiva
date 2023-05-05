/**
 * Dado um vetor de inteiros, encontre e imprima a soma de todos os números pares.
 */

#include <iostream>
#include <vector>

int main()
{
   std::vector<int> integers{1, -2, 3, 4, -5, 6, 7, -8, 9, 10};

   int evenSum{0};
   for (int integer : integers)
   {
      if (integer % 2 == 0)
      {
         evenSum += integer;
      }
   }

   std::cout << "Sum of even integers: " << evenSum << '\n';

   return 0;
}
