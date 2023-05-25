/**
 * Task: Design a software for a library.
 * This software should keep a record of all available books and the quantity of each one of them.
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <utility>

std::string askForBookTitle();
unsigned askForCopiesAmount();

int main()
{
   std::map<std::string, unsigned> booksQuantityRecord{};

   const std::string ADD_BOOK{"add"};
   const std::string REMOVE_BOOK{"remove"};
   const std::string PRINT_RECORD{"print"};
   const std::string EXIT{"exit"};
   std::string choice;
   do
   {
      std::cout << "\n- Options:\n"
                << "[-] " << ADD_BOOK << "\n"
                << "[-] " << REMOVE_BOOK << "\n"
                << "[-] " << PRINT_RECORD << "\n"
                << "[-] " << EXIT << "\n"
                << ": ";
      std::cin >> choice;

      if (choice == ADD_BOOK)
      {
         std::string bookTitle{askForBookTitle()};
         unsigned amount{askForCopiesAmount()};

         if (booksQuantityRecord.find(bookTitle) == booksQuantityRecord.end())
         {
            booksQuantityRecord[bookTitle] = amount;
            std::cout << "Added an entry for " << bookTitle << '\n';
         }
         else
         {
            booksQuantityRecord[bookTitle] = amount;
            std::cout << "Added a new copy for " << bookTitle << '\n';
         }
      }
      else if (choice == REMOVE_BOOK)
      {
         std::string bookTitle{askForBookTitle()};
         unsigned amount{askForCopiesAmount()};

         if (booksQuantityRecord.find(bookTitle) == booksQuantityRecord.end())
         {
            std::cout << "Book not in record!\n";
         }
         else
         {
            if (amount >= booksQuantityRecord[bookTitle])
            {
               booksQuantityRecord.erase(bookTitle);
            }
            else
            {
               booksQuantityRecord[bookTitle] -= amount;
            }
         }
      }
      else if (choice == PRINT_RECORD)
      {
         for (const auto &[book, amount] : booksQuantityRecord)
         {
            std::cout << book << ": " << amount << " copies\n";
         }
      }
   } while (choice != EXIT);

   return 0;
}

std::string askForBookTitle()
{
   std::cout << "Type the title of the book: ";

   std::string bookTitle;
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   std::getline(std::cin, bookTitle);

   std::transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(),
                  [](char c)
                  { return std::tolower(c); });

   return bookTitle;
}

unsigned askForCopiesAmount()
{
   std::cout << "Type the amount of copies: ";
   unsigned amount;
   std::cin >> amount;

   return amount;
}
