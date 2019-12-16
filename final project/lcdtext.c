#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "lcdtext.h"

setStrTextLCD(int line, char* str)
{
   char strCmd[80];
   int result;

   sprintf(strCmd, "./textlcdtest %d '%s'", line, str);
   result = system(strCmd);
}

