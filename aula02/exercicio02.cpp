/**
 * Dado um conjunto de nomes brasileiros, encontre e imprima todos os nomes que contêm mais de 2 vogais.
 */

#include <algorithm>
#include <iostream>
#include <set>

inline bool isVowel(char ch)
{
   const std::string vowels{"aeiouAEIOU"};

   // can we find ch inside vowels?
   return (find(vowels.begin(), vowels.end(), ch) != vowels.end());
}

int countVowels(const std::string &str)
{
   int vowelCount{0};
   for (char ch : str)
   {
      if (isVowel(ch))
      {
         ++vowelCount;
      }
   }

   return vowelCount;
}

int main()
{
   const std::set<std::string> brazilianNames{"Ana", "Fabio", "Mateus", "Julia", "Pedro", "Helena", "Miguel", "Mariana"};

   constexpr int MIN_VOWEL_COUNT{2};
   for (const std::string &name : brazilianNames)
   {
      if (countVowels(name) > MIN_VOWEL_COUNT)
      {
         std::cout << name << ' ';
      }
   }
   std::cout << '\n';

   return 0;
}
