/**
 * Task: Implement a management system for a medical clinic.
 * Ensure that patients are attended in the order they arrive and that this order is correctly tracked.
 */

#include <iostream>
#include <limits>
#include <queue>
#include <string>

void registerNewPatient(std::queue<std::string> &patients);
void getNextPatient(std::queue<std::string> &patients);
void printPatientQueue(std::queue<std::string> patients);

int main()
{
   std::queue<std::string> patients{};

   const std::string NEXT_PATIENT("next");
   const std::string ADD_PATIENT("add");
   const std::string PRINT_PATIENT_QUEUE("print");
   const std::string EXIT{"exit"};
   std::string choice;
   do
   {
      std::cout << "\n- Options:\n"
                << "[-] " << ADD_PATIENT << "\n"
                << "[-] " << NEXT_PATIENT << "\n"
                << "[-] " << PRINT_PATIENT_QUEUE << "\n"
                << "[-] " << EXIT << "\n"
                << ": ";
      std::cin >> choice;

      if (choice == ADD_PATIENT)
      {
         registerNewPatient(patients);
      }
      else if (choice == NEXT_PATIENT)
      {
         getNextPatient(patients);
      }
      else if (choice == PRINT_PATIENT_QUEUE)
      {
         printPatientQueue(patients);
      }
   } while (choice != EXIT);

   return 0;
}

void registerNewPatient(std::queue<std::string> &patients)
{
   std::cout << "New patient name: ";
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   std::string name;
   std::getline(std::cin, name);
   patients.push(name);
}

void getNextPatient(std::queue<std::string> &patients)
{
   if (!patients.empty())
   {
      std::string nextPatient{patients.front()};
      std::cout << "Next patient name: " << nextPatient << '\n';
      patients.pop();
   }
   else
   {
      std::cout << "The queue is empty!\n";
   }
}

void printPatientQueue(std::queue<std::string> patients)
{
   std::size_t patientsSize{patients.size()};
   std::cout << "Size of the queue: " << patientsSize << '\n';
   for (std::size_t i{1}; i <= patientsSize; ++i)
   {
      std::cout << i << "o: " << patients.front() << '\n';
      patients.pop();
   }
}
