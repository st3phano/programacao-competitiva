/**
 * Task: Create an application for a restaurant to manage customer orders.
 * The application should allow customers to choose whether their orders
 * will be delivered first (as a VIP order) or added to the normal queue.
 */

#include <cstddef>
#include <deque>
#include <iostream>
#include <string>

int main()
{
   std::deque<std::string> orders;
   unsigned vipOrderCount{0};

   const std::string ADD_ORDER{"add"};
   const std::string GET_NEXT_ORDER{"next"};
   const std::string REMOVE_ORDER{"remove"};
   const std::string PRINT_ORDERS{"print"};
   const std::string EXIT{"exit"};

   std::string options{"\n- Options:\n" +
                       ADD_ORDER + "\n" +
                       GET_NEXT_ORDER + "\n" +
                       PRINT_ORDERS + "\n" +
                       REMOVE_ORDER + "\n" +
                       EXIT + "\n" +
                       ": "};

   std::string choice;
   while (std::cout << options, std::cin >> choice && choice != EXIT)
   {
      if (choice == ADD_ORDER)
      {
         std::cout << "Order: ";
         std::string order;
         std::cin >> order;

         const std::string NORMAL_ORDER{"normal"};
         const std::string VIP_ORDER{"vip"};
         std::cout << "\n- Options:\n"
                   << NORMAL_ORDER << "\n"
                   << VIP_ORDER << "\n"
                   << ": ";

         std::string orderType;
         std::cin >> orderType;
         if (orderType == VIP_ORDER)
         {
            orders.insert(orders.begin() + vipOrderCount, order);
            ++vipOrderCount;
         }
         else
         {
            orders.push_back(order);
         }
      }
      else if (choice == GET_NEXT_ORDER)
      {
         std::cout << orders.front();
         orders.pop_front();
      }
      else if (choice == PRINT_ORDERS)
      {
         std::size_t orderNumber{1};
         for (const auto &order : orders)
         {
            std::cout << orderNumber << ". " << order << '\n';
            ++orderNumber;
         }
      }
      else if (choice == REMOVE_ORDER)
      {
         std::cout << "Order number: ";
         std::size_t orderNumber;
         std::cin >> orderNumber;

         if ((orderNumber < 1) || (orderNumber > orders.size()))
         {
            std::cout << "Order " << orderNumber << " does not exist!\n";
         }
         else
         {
            std::size_t orderIndex{orderNumber - 1};
            orders.erase(orders.begin() + orderIndex);
         }
      }
   }

   return 0;
}
