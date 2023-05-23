/**
 * Task: Develop a basic text editor with undo/redo functionality.
 * Each action performed in the editor must be recorded to enable undo/redo.
 */

#include <iostream>
#include <stack>
#include <string>

void printStack(std::stack<std::string> s)
{
   while (!s.empty())
   {
      std::cout << s.top() << '\t';
      s.pop();
   }
   std::cout << '\n';
}

int main()
{
   std::stack<std::string> textEditor;
   std::stack<std::string> undoStack;

   const std::string INSERT{"insert"};
   const std::string UNDO{"undo"};
   const std::string REDO{"redo"};
   const std::string PRINT{"print"};
   const std::string EXIT{"exit"};
   std::string choice;
   do
   {
      std::cout << "\n- Options:\n"
                << "[-] " << INSERT << "\n"
                << "[-] " << UNDO << "\n"
                << "[-] " << REDO << "\n"
                << "[-] " << PRINT << "\n"
                << "[-] " << EXIT << "\n"
                << ": ";
      std::cin >> choice;

      if (choice == INSERT)
      {
         std::string toInsert{};
         std::cin >> toInsert;
         textEditor.push(toInsert);
      }
      else if (choice == UNDO)
      {
         if (!textEditor.empty())
         {
            undoStack.push(textEditor.top());
            textEditor.pop();
         }
         else
         {
            std::cout << "No actions to undo!\n";
         }
      }
      else if (choice == REDO)
      {
         if (!undoStack.empty())
         {
            textEditor.push(undoStack.top());
            undoStack.pop();
         }
         else
         {
            std::cout << "No actions to redo!\n";
         }
      }
      else if (choice == PRINT)
      {
         printStack(textEditor);
      }
   } while (choice != "exit");

   return 0;
}
