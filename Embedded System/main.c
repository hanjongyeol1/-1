#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <linux/input.h>
#include "led.h"
#include "buzzer.h"
#include "button.h"

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
	int messageID = msgget (MESSAGE_ID, IPC_CREAT|0666);	//To Receive Message from Library.
	BUTTON_MSG_T rxMsg;

	while (1)
	{
		msgrcv(messageID, &rxMsg, sizeof(rxMsg) - sizeof(long int),0 ,0);
		printf ("ReceivedMessage:%d-%d",rxMsg.keyInput, rxMsg.pressed);
		//rxMsg.pressed == 0 -> Really Pressed.
		int scale = 0;
		if (rxMsg.pressed!=0){
		switch(rxMsg.keyInput)
			{
				if (rxMsg.pressed!=0)
			    case KEY_HOME: 
				printf("DOREMI SONG):");		
				ma("doremisong.bmp");
				scale = 0; buzzerPlaySong(scale); //도
				usleep(400000);
				scale=1; buzzerPlaySong(scale); //레
				usleep(200000);
				scale = 2; buzzerPlaySong(scale); //미
				usleep(600000);
				scale = 0; buzzerPlaySong(scale); //도
				usleep(400000);
				scale = 2; buzzerPlaySong(scale); //미
				usleep(400000);
				scale = 0; buzzerPlaySong(scale); //도
				usleep(400000);
				scale = 2; buzzerPlaySong(scale); //미
				usleep(600000);
				
				scale=1; buzzerPlaySong(scale); //레
				usleep(400000);
				scale = 2; buzzerPlaySong(scale); //미
				usleep(200000);
				scale = 3; buzzerPlaySong(scale); //파
				usleep(150000);
				scale = 3; buzzerPlaySong(scale); //파
				usleep(150000);
				scale = 2; buzzerPlaySong(scale); //미
				usleep(200000);
				scale=1; buzzerPlaySong(scale); //레
				usleep(200000);
				scale = 3; buzzerPlaySong(scale); //파
				usleep(600000);
				
				scale = 2; buzzerPlaySong(scale); //미
				usleep(400000);
				scale=3; buzzerPlaySong(scale); //파
				usleep(200000);
				scale = 4; buzzerPlaySong(scale); //솔
				usleep(600000);
				scale = 2; buzzerPlaySong(scale); //미
				usleep(400000);
				scale = 4; buzzerPlaySong(scale); //솔
				usleep(400000);
				scale = 2; buzzerPlaySong(scale); //미
				usleep(400000);
				scale = 4; buzzerPlaySong(scale); //솔
				usleep(600000);
				
			    scale=3; buzzerPlaySong(scale); //파
				usleep(400000);
				scale = 4; buzzerPlaySong(scale); //솔
				usleep(200000);
				scale = 5; buzzerPlaySong(scale); //라
				usleep(150000);
				scale = 5; buzzerPlaySong(scale); //라
				usleep(150000);
				scale = 4; buzzerPlaySong(scale); //솔
				usleep(200000);
				scale=3; buzzerPlaySong(scale); //파
				usleep(200000);
				scale = 5; buzzerPlaySong(scale); //라
				usleep(600000);
				
				scale=4; buzzerPlaySong(scale); //솔
				usleep(400000);
				scale = 0; buzzerPlaySong(scale); //도
				usleep(200000);
				scale = 1; buzzerPlaySong(scale); //레
				usleep(200000);
				scale = 2; buzzerPlaySong(scale); //미
				usleep(200000);
				scale = 3; buzzerPlaySong(scale); //파
				usleep(200000);
				scale=4; buzzerPlaySong(scale); //솔
				usleep(200000);
				scale = 5; buzzerPlaySong(scale); //라
				usleep(600000);
				
				scale=5; buzzerPlaySong(scale); //라
				usleep(400000);
				scale = 1; buzzerPlaySong(scale); //레
				usleep(200000);
				scale = 2; buzzerPlaySong(scale); //미
				usleep(200000);
				scale = 3; buzzerPlaySong(scale); //파
				usleep(200000);
				scale = 4; buzzerPlaySong(scale); //솔
				usleep(200000);
				scale=5; buzzerPlaySong(scale); //라
				usleep(200000);
				scale = 6; buzzerPlaySong(scale); //시
				usleep(600000);
				
				scale=6; buzzerPlaySong(scale); //시
				usleep(400000);
				scale = 2; buzzerPlaySong(scale); //미
				usleep(200000);
			    scale = 3; buzzerPlaySong(scale); //파
			    usleep(200000);
				scale = 4; buzzerPlaySong(scale); //솔
				usleep(200000);
				scale = 5; buzzerPlaySong(scale); //라
				usleep(200000);
				scale=6; buzzerPlaySong(scale); //시
				usleep(200000);
				scale=7; buzzerPlaySong(scale); //도
				usleep(600000);
				
				scale=7; buzzerPlaySong(scale); //도
				usleep(150000);
				scale=6; buzzerPlaySong(scale); //시
				usleep(200000);
				scale=5; buzzerPlaySong(scale); //라
				usleep(200000);
				scale = 3; buzzerPlaySong(scale); //파
				usleep(200000);
				scale = 6; buzzerPlaySong(scale); //시
				usleep(200000);
				scale = 4; buzzerPlaySong(scale); //솔
                usleep(200000);
				scale=7; buzzerPlaySong(scale); //도
				usleep(200000);
				
				scale=7; buzzerPlaySong(scale); //도
			    usleep(200000);
				scale = 0; buzzerPlaySong(scale); //도
				usleep(200000);
				scale = 1; buzzerPlaySong(scale); //레
				usleep(200000);
				scale = 2; buzzerPlaySong(scale); //미
				usleep(200000);
				scale = 4; buzzerPlaySong(scale); //파
				usleep(200000);
				scale=3; buzzerPlaySong(scale); //솔
				usleep(200000);
				scale = 5; buzzerPlaySong(scale); //라
				usleep(200000);
				scale=6; buzzerPlaySong(scale); //시
				usleep(200000);
				scale=7; buzzerPlaySong(scale); //도
				usleep(300000);
				scale = 4; buzzerPlaySong(scale); //솔
                usleep(300000);
				scale=7; buzzerPlaySong(scale); //도
				usleep(600000);
     			break;
			
			case KEY_BACK: 
				printf("AIRPLANE):"); 
				scale = 1;
			break;
			case KEY_SEARCH: 
				printf("Search key):"); 
				scale = 2;
			break;
			case KEY_MENU: 
				printf("Back key):");
				scale = 3;
			break;
			case KEY_VOLUMEUP: 
				printf("Menu key):"); 
				scale = 4;
			break;
			case KEY_VOLUMEDOWN:
				printf("Volume down key):");
				scale = 5;
			break;
		}
}
	ledExit();
	buzzerExit();
	buttonExit();
	return 1;
}
}

