/**
 * Given an array of integers, find and print the sum of all even numbers.
 */

#include <iostream>
#include <vector>

int main()
{
   std::vector<int> integers{1, -2, 3, 4, -5, 6, 7, -8, 9, 10};

   int sumEvenIntegers{0};
   for (int integer : integers)
   {
      if (integer % 2 == 0)
      {
         sumEvenIntegers += integer;
      }
   }

   std::cout << "Sum of even integers: " << sumEvenIntegers << '\n';

   return 0;
}
