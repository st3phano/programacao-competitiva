/**
 * Optimization comparison between compilers in regards to matrix multiplication
 *
 * GCC is a little faster than CLANG, CL lags way behind the two
 *
 * From fastWithAt() to fastestWithAt():
 * ~ GCC -O3: Huge improvement
 * ~ CLANG -O3: Little improvement
 * ~ CL -O2: Huge improvement
 *
 * From fast() to fastest():
 * ~ GCC -O3: No improvement
 * ~ CLANG -O3: Little improvement
 * ~ CL -O2: Huge improvement, CL seems unable to optimize the third nested loop
 */

#include <chrono>
#include <cstddef>
#include <iostream>
#include <vector>

template <typename T, typename... Args>
auto printTimeSpentOnFunc(T func, Args &...args)
{
   auto startTime{std::chrono::system_clock::now()};
   auto returnValue{func(args...)};
   auto endTime{std::chrono::system_clock::now()};

   auto durationMs{std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()};
   std::cout << "Execution time: " << durationMs << " milliseconds\n";

   return returnValue;
}

using intVector = std::vector<int>;
using intMatrix = std::vector<intVector>;

void printMatrix(const intMatrix &matrix)
{
   for (const auto &row : matrix)
   {
      for (const auto &element : row)
      {
         std::cout << element << '\t';
      }
      std::cout << '\n';
   }
}

intMatrix multiplyMatrixSlow(const intMatrix &matrixA, const intMatrix &matrixB)
{
   const std::size_t rowsMatrixA{matrixA.size()};
   const std::size_t rowsMatrixB{matrixB.size()};
   const std::size_t colsMatrixB{matrixB[0].size()};

   intMatrix matrixResult(rowsMatrixA, intVector(colsMatrixB));

   for (int row{0}; row < rowsMatrixA; ++row)
   {
      for (int col{0}; col < colsMatrixB; ++col)
      {
         int sum{0};
         for (int rowOrCol{0}; rowOrCol < rowsMatrixB; ++rowOrCol)
         {
            sum += matrixA[row][rowOrCol] * matrixB[rowOrCol][col];
         }
         matrixResult[row][col] = sum;
      }
   }

   return matrixResult;
}

intMatrix multiplyMatrixFastWithAt(const intMatrix &matrixA, const intMatrix &matrixB)
{
   const std::size_t rowsMatrixA{matrixA.size()};
   const std::size_t rowsMatrixB{matrixB.size()};
   const std::size_t colsMatrixB{matrixB[0].size()};

   intMatrix matrixResult(rowsMatrixA, intVector(colsMatrixB, 0));

   for (int row{0}; row < rowsMatrixA; ++row)
   {
      for (int rowOrCol{0}; rowOrCol < rowsMatrixB; ++rowOrCol)
      {
         for (int col{0}; col < colsMatrixB; ++col)
         {
            matrixResult.at(row).at(col) += matrixA.at(row).at(rowOrCol) * matrixB.at(rowOrCol).at(col);
         }
      }
   }

   return matrixResult;
}

intMatrix multiplyMatrixFastestWithAt(const intMatrix &matrixA, const intMatrix &matrixB)
{
   const std::size_t rowsMatrixA{matrixA.size()};
   const std::size_t rowsMatrixB{matrixB.size()};
   const std::size_t colsMatrixB{matrixB[0].size()};

   intMatrix matrixResult(rowsMatrixA, intVector(colsMatrixB, 0));

   for (std::size_t row{0}; row < rowsMatrixA; ++row)
   {
      intVector &rowResut{matrixResult.at(row)};
      const intVector &rowA{matrixA.at(row)};

      for (std::size_t rowOrCol{0}; rowOrCol < rowsMatrixB; ++rowOrCol)
      {
         const int elemA{rowA.at(rowOrCol)};
         const intVector &rowB{matrixB.at(rowOrCol)};

         for (std::size_t col{0}; col < colsMatrixB; ++col)
         {
            rowResut.at(col) += elemA * rowB.at(col);
         }
      }
   }

   return matrixResult;
}

intMatrix multiplyMatrixFast(const intMatrix &matrixA, const intMatrix &matrixB)
{
   const std::size_t rowsMatrixA{matrixA.size()};
   const std::size_t rowsMatrixB{matrixB.size()};
   const std::size_t colsMatrixB{matrixB[0].size()};

   intMatrix matrixResult(rowsMatrixA, intVector(colsMatrixB, 0));

   for (int row{0}; row < rowsMatrixA; ++row)
   {
      for (int rowOrCol{0}; rowOrCol < rowsMatrixB; ++rowOrCol)
      {
         for (int col{0}; col < colsMatrixB; ++col)
         {
            matrixResult[row][col] += matrixA[row][rowOrCol] * matrixB[rowOrCol][col];
         }
      }
   }

   return matrixResult;
}

intMatrix multiplyMatrixFastest(const intMatrix &matrixA, const intMatrix &matrixB)
{
   const std::size_t rowsMatrixA{matrixA.size()};
   const std::size_t rowsMatrixB{matrixB.size()};
   const std::size_t colsMatrixB{matrixB[0].size()};

   intMatrix matrixResult(rowsMatrixA, intVector(colsMatrixB, 0));

   for (std::size_t row{0}; row < rowsMatrixA; ++row)
   {
      intVector &rowResut{matrixResult[row]};
      const intVector &rowA{matrixA[row]};

      for (std::size_t rowOrCol{0}; rowOrCol < rowsMatrixB; ++rowOrCol)
      {
         const int elemA{rowA[rowOrCol]};
         const intVector &rowB{matrixB[rowOrCol]};

         for (std::size_t col{0}; col < colsMatrixB; ++col)
         {
            rowResut[col] += elemA * rowB[col];
         }
      }
   }

   return matrixResult;
}

int main()
{
   constexpr std::size_t MATRIX_SIZE{1000};

   const intMatrix matrixA(MATRIX_SIZE * 2, intVector(MATRIX_SIZE, 1));
   const intMatrix matrixB(MATRIX_SIZE, intVector(MATRIX_SIZE * 3, 1));

   std::cout << "[-] Slow:\n";
   printTimeSpentOnFunc(&multiplyMatrixSlow, matrixA, matrixB);

   std::cout << "[-] FastWithAt:\n";
   printTimeSpentOnFunc(&multiplyMatrixFastWithAt, matrixA, matrixB);

   std::cout << "[-] FastestWithAt:\n";
   printTimeSpentOnFunc(&multiplyMatrixFastestWithAt, matrixA, matrixB);

   std::cout << "[-] Fast:\n";
   printTimeSpentOnFunc(&multiplyMatrixFast, matrixA, matrixB);

   std::cout << "[-] Fastest:\n";
   printTimeSpentOnFunc(&multiplyMatrixFastest, matrixA, matrixB);

   return 0;
}
