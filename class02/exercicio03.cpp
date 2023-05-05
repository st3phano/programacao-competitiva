/**
 * Given an array of integers, remove all numbers that are multiples of 3 and print the resulting array.
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
   std::vector<int> integers{1, -2, 3, 4, -5, 6, 7, -8, 9, 10, 50, -23, 78, 100, -345};

   auto beginEraseIter{std::remove_if(integers.begin(), integers.end(),
                                      [](int x) -> bool
                                      { return x % 3 == 0; })};
   integers.erase(beginEraseIter, integers.end());

   for (const int integer : integers)
   {
      std::cout << integer << '\t';
   }
   std::cout << '\n';

   return 0;
}