/**
 * Task: Develop a student management system for a university.
 * The system must store and quickly retrieve student details based on their enrollment number.
 */

#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

std::string requestInputLine(const std::string &prompt);
void toLowerCase(std::string &str);
unsigned requestEnrollmentNumber();
unsigned getEnrollmentNumber(const std::unordered_map<unsigned, std::string> &students, const std::string &studentName);

int main()
{
   std::unordered_map<unsigned, std::string> students{};
   unsigned nextEnrollmentNumber{1};

   const std::string ADD_STUDENT{"add"};
   const std::string REMOVE_STUDENT{"remove"};
   const std::string RETRIEVE_STUDENT{"retrieve"};
   const std::string PRINT_STUDENTS{"print"};
   const std::string EXIT{"exit"};
   const std::string OPTIONS{"\n - Options:\n" +
                             ADD_STUDENT + '\n' +
                             REMOVE_STUDENT + '\n' +
                             RETRIEVE_STUDENT + '\n' +
                             PRINT_STUDENTS + '\n' +
                             EXIT + '\n' +
                             ": "};

   std::string choice;
   while (std::cout << OPTIONS, std::cin >> choice && choice != EXIT)
   {
      if (choice == ADD_STUDENT)
      {
         std::string studentName{requestInputLine("Student name: ")};
         toLowerCase(studentName);

         if (getEnrollmentNumber(students, studentName) == 0)
         {
            students[nextEnrollmentNumber] = studentName;
            ++nextEnrollmentNumber;
         }
         else
         {
            std::cout << "Student already enrolled!\n";
         }
      }
      else if (choice == REMOVE_STUDENT)
      {
         unsigned enrollmentNumber{requestEnrollmentNumber()};

         if (students.erase(enrollmentNumber) == 1)
         {
            std::cout << "Student record removed successfully!\n";
         }
         else
         {
            std::cout << "No record matching number " << enrollmentNumber << " was found!\n";
         }
      }
      else if (choice == RETRIEVE_STUDENT)
      {
         unsigned enrollmentNumber{requestEnrollmentNumber()};

         if (students.find(enrollmentNumber) != students.end())
         {
            std::cout << enrollmentNumber << " - " << students[enrollmentNumber] << '\n';
         }
         else
         {
            std::cout << "No record matching number " << enrollmentNumber << " was found!\n";
         }
      }
      else if (choice == PRINT_STUDENTS)
      {
         if (!students.empty())
         {
            for (const auto &student : students)
            {
               std::cout << student.first << " - " << student.second << '\n';
            }
         }
         else
         {
            std::cout << "No record found!\n";
         }
      }
   }

   return 0;
}

std::string requestInputLine(const std::string &prompt)
{
   std::cout << prompt;
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   std::string line;
   std::getline(std::cin, line);

   return line;
}

void toLowerCase(std::string &str)
{
   for (auto &ch : str)
   {
      ch = std::tolower(ch);
   }
}

unsigned requestEnrollmentNumber()
{
   std::cout << "Enrollment number: ";
   unsigned enrollmentNumber;
   std::cin >> enrollmentNumber;

   return enrollmentNumber;
}

unsigned getEnrollmentNumber(const std::unordered_map<unsigned, std::string> &students, const std::string &studentName)
{
   for (const auto &student : students)
   {
      if (student.second == studentName)
      {
         return student.first;
      }
   }

   return 0;
}
