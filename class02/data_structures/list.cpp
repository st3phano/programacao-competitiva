/**
 * Task: Build a music app that allows users to create their own playlists.
 * Users should be able to add, remove and move songs within the playlist.
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <string>

std::string requestInputLine(const std::string &prompt);
std::string toLowerCase(const std::string &str);

int main()
{
   std::list<std::string> playlist{};

   const std::string ADD_SONG{"add"};
   const std::string REMOVE_SONG{"remove"};
   const std::string MOVE_SONG{"move"};
   const std::string PRINT_SONGS{"print"};
   const std::string EXIT{"exit"};
   const std::string options{"\n- Options:\n" +
                             ADD_SONG + "\n" +
                             REMOVE_SONG + "\n" +
                             MOVE_SONG + "\n" +
                             PRINT_SONGS + "\n" +
                             EXIT + "\n" +
                             ": "};

   std::string choice;
   while (std::cout << options, std::cin >> choice && choice != EXIT)
   {
      if (choice == ADD_SONG)
      {
         std::string songName{toLowerCase(requestInputLine("Song name: "))};
         playlist.push_back(songName);
      }
      else if (choice == REMOVE_SONG)
      {
         std::cout << "Song index: ";
         std::size_t songIndex;
         std::cin >> songIndex;

         if (songIndex < playlist.size())
         {
            auto songIndexIter{playlist.begin()};
            std::advance(songIndexIter, songIndex);
            playlist.erase(songIndexIter);
         }
         else
         {
            std::cout << "Invalid index!\n";
         }
      }
      else if (choice == MOVE_SONG)
      {
         std::cout << "From index: ";
         std::size_t fromIndex;
         std::cin >> fromIndex;

         std::cout << "To index: ";
         std::size_t toIndex;
         std::cin >> toIndex;

         if ((fromIndex != toIndex) && (fromIndex < playlist.size()) && (toIndex < playlist.size()))
         {
            auto fromIndexIter{playlist.begin()};
            std::advance(fromIndexIter, fromIndex);

            if (toIndex > fromIndex)
            {
               ++toIndex; // std::splice inserts BEFORE the destination
            }
            auto toIndexIter{playlist.begin()};
            std::advance(toIndexIter, toIndex);

            playlist.splice(toIndexIter, playlist, fromIndexIter);
         }
         else
         {
            std::cout << "Invalid index(es)!\n";
         }
      }
      else if (choice == PRINT_SONGS)
      {
         if (playlist.empty())
         {
            std::cout << "The playlist is empty!\n";
         }
         else
         {
            std::size_t i{0};
            for (const auto &song : playlist)
            {
               std::cout << i << ". " << song << "\n";
               ++i;
            }
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

std::string toLowerCase(const std::string &str)
{
   std::string lowerCase(str.size(), '\0');
   std::transform(str.begin(), str.end(), lowerCase.begin(),
                  [](char c) -> char
                  {
                     return std::tolower(c);
                  });

   return lowerCase;
}
