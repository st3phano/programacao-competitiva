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
   std::stack<std::string> textEditor{};
   std::stack<std::string> undoStack{};

   const std::string INSERT_WORD{"insert"};
   const std::string UNDO_WORD{"undo"};
   const std::string REDO_WORD{"redo"};
   const std::string PRINT_TEXT{"print"};
   const std::string EXIT{"exit"};
   std::string choice;
   do
   {
      std::cout << "\n- Options:\n"
                << "[-] " << INSERT_WORD << "\n"
                << "[-] " << UNDO_WORD << "\n"
                << "[-] " << REDO_WORD << "\n"
                << "[-] " << PRINT_TEXT << "\n"
                << "[-] " << EXIT << "\n"
                << ": ";
      std::cin >> choice;

      if (choice == INSERT_WORD)
      {
         std::string toInsert{};
         std::cin >> toInsert;
         textEditor.push(toInsert);
      }
      else if (choice == UNDO_WORD)
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
      else if (choice == REDO_WORD)
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
      else if (choice == PRINT_TEXT)
      {
         printStack(textEditor);
      }
   } while (choice != "exit");

   return 0;
}
