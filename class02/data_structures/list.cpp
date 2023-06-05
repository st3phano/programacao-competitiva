/**
 * Task: Build a music app that allows users to create their own playlists.
 * Users should be able to add, remove and move songs within the playlist.
 */

#include <algorithm>
#include <cctype>
#include <iostream>
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
      else if (choice == MOVE_SONG) // TO-DO: fix move songs to a higher index
      {
         std::cout << "Song index: ";
         std::size_t songIndex;
         std::cin >> songIndex;

         std::cout << "New index: ";
         std::size_t newIndex;
         std::cin >> newIndex;

         if (songIndex < playlist.size() && newIndex < playlist.size())
         {
            auto songIndexIter{playlist.begin()};
            std::advance(songIndexIter, songIndex);

            auto newIndexIter{playlist.begin()};
            std::advance(newIndexIter, newIndex);

            playlist.splice(newIndexIter, playlist, songIndexIter);
         }
         else
         {
            std::cout << "Invalid index(es)!\n";
         }
      }
      else if (choice == PRINT_SONGS)
      {
         std::size_t i{0};
         for (const auto &song : playlist)
         {
            std::cout << i << ". " << song << "\n";
            ++i;
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
