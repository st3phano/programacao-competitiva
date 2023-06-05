/**
 * An online store wants to analyze the sales history of a particular product to improve its marketing strategy.
 * The goal is to identify the period of time in which the increase in sales was the greatest possible.
 * Given an array of integers representing the daily sales of a product,
 * find the contiguous subsequence with the greatest variation in sales and determine its value.
 *
 * Input: The first line contains a single integer N (2 <= N <= 10^5), representing the number of days.
 * The second line contains N integers A[i] (0 <= A[i] <= 10^4), representing the daily sales of the product.
 *
 * Output: Print a single integer, representing the value of the greatest variation in sales in a contiguous period.
 *
 * Input Example:
 * 7
 * 3 4 7 1 2 6 9
 *
 * Output Example:
 * 8
 *
 * Explanation: The greatest variation is between 1 and 9 (days 4 and 7), with a variation of 8.
 */

#include <iostream>
#include <vector>

int main()
{
   int days;
   std::cin >> days; // number of days: 2 <= N <= 10^5
   int salesYesterday, salesToday;
   std::cin >> salesYesterday >> salesToday;

   int currentVariation{salesToday - salesYesterday};
   int greatestVariation{currentVariation};
   for (int day{3}; day <= days; ++day)
   {
      salesYesterday = salesToday;
      std::cin >> salesToday;

      // Kadane's Algorithm
      int salesTodayMinusYesterday{salesToday - salesYesterday};
      currentVariation += salesTodayMinusYesterday;
      if (currentVariation < salesTodayMinusYesterday)
      {
         currentVariation = salesTodayMinusYesterday;
      }
      if (greatestVariation < currentVariation)
      {
         greatestVariation = currentVariation;
      }
   }

   std::cout << greatestVariation << '\n';

   return 0;
}
