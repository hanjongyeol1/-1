#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <linux/input.h>
#include "led.h"
#include "buzzer.h"
#include "button.h"
#include "lcdtext.h"
#include "fnd.h"
#include "bitmap.h"

int main (void)
{
   printf ("Buzzer Piano!\r\n");
   if (ledInit()== 0)
   {
      printf ("LED init Failed!\r\n");
      return 0;
   }
   if (buzzerInit() == 0)
   {
      printf ("Buzzer init Failed!\r\n");
      return 0;
   }
   if (buttonInit() == 0)
   {
      printf ("Button init Failed!\r\n");
      return 0;
   }
   int messageID = msgget (MESSAGE_ID, IPC_CREAT|0666);   //To Receive Message from Library.
   BUTTON_MSG_T rxMsg;

   while (1)
   {
      msgrcv(messageID, &rxMsg, sizeof(rxMsg) - sizeof(long int),0 ,0);
      printf ("ReceivedMessage:%d-%d",rxMsg.keyInput, rxMsg.pressed);
      //rxMsg.pressed == 0 -> Really Pressed.
      int scale = 0;
      if(rxMsg.pressed != 0)
      {
      switch(rxMsg.keyInput)
      {
         case KEY_HOME:
             ma("do.bmp");
            printf("DOREMI SONG):");      
            setStrTextLCD(1, "DOREMI SONG");
            setStrTextLCD(2, "Playing...");
            ledOnAll();
            fndDisp(1,0x00);
            doremi();
            ledOffAll();
            fndOff();
            ma("home.bmp");
         break;
         
         case KEY_BACK: 
            ma("airplane.bmp"); //
            printf("Airplane):"); 
            setStrTextLCD(1, "Airplane");
            setStrTextLCD(2, "Playing...");
            ledOnAll();
             fndDisp(2,0x00);
            plane();
            ledOffAll();
            fndOff();
            ma("home.bmp");
            scale = 1;
         break;
         case KEY_SEARCH: 
            ma("school.bmp");
            printf("School Bell):"); 
            setStrTextLCD(1, "School Bell");
            setStrTextLCD(2, "Playing...");
            ledOnAll();
             fndDisp(3,0x00);
             schoolbell();
            ledOffAll();
            fndOff();
            ma("home.bmp");
        break;
         case KEY_MENU: 
            ma("happy.bmp");
            printf("HappyBirthday):");
            setStrTextLCD(1, "HappyBD");
            setStrTextLCD(2, "Playing...");
            ledOnAll();
            birthday();
            ledOffAll();
            ma("home.bmp");
         break;
         case KEY_VOLUMEUP: 
            ma("jingle.bmp");
            printf("JingleBell):"); 
            setStrTextLCD(1, "JingleBell");
            setStrTextLCD(2, "Playing...");
            ledOnAll();
           jinglebell();
            ledOffAll();
            ma("home.bmp");
         break;
         case  KEY_VOLUMEDOWN:
             ma("home.bmp");
            printf("HOME");	
         break;
      }
         buzzerPlaySong(scale);
      }
      else
      {
		ledOffAll();
        buzzerStopSong();             
      }
      
   }

   ledExit();
   buzzerExit();
   buttonExit();
   return 1;
}

