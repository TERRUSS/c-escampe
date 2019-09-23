
#include "utils.h"

int myrand (void) {
   static int first = 0;

   if (first == 0)
   {
      srand (time (NULL));
      first = 1;
   }
   return (rand ());
}
