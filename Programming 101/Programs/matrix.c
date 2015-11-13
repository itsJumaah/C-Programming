#include <ctime>
#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
   //green color for text
   system("color 0a");

   //random seed
   srand(time(0));

   char random_char = ((rand() % 127));
   bool going = true, checking = true;

   while (going = true)
   {
      //draw row of characters (38 characters)
      for (int x = 0; x < 76; x++)
      {
         //generate first char
         random_char = ((rand() % 127) + 50);
         checking = true;
         while (checking)
         {
            if  ( //check for:
               // Bad/Small characters.
                  (random_char == 32) || (random_char == 39) || (random_char == 46) ||
                  (random_char == 44) || (random_char == 34) || (random_char == 45) ||
                  (random_char == 58) || (random_char == 59) || (random_char == 94) ||
                  (random_char == 95) || (random_char == 96) || (random_char == 126)
               // If bad character is generated -> generate new random character and check if it is bad
                )
            random_char = ((rand() % 127) + 50);

            //Good character found -> Continue to print it
            else break;
         }
         //Print character + white space
         cout << random_char << " ";
      }
      //Full row of characters successfully printed -> continue for next row
      cout << endl;

      //Delay
      Sleep(20);
   }
   cin.get();
   return 0;
}