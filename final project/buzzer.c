#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>


#define MAX_SCALE_STEP   14
#define BUZZER_BASE_SYS_PATH   "/sys/bus/platform/devices/"
#define BUZZER_FILENAME  "peribuzzer"
#define BUZZER_ENABLE_NAME      "enable"
#define BUZZER_FREQUENCY_NAME   "frequency"
char gBuzzerBaseSysDir[128];
int scale=0;

const int musicScale[MAX_SCALE_STEP] =
{
   262, //도
   277, // 도#
   294, // 레
   311, // 레#
   330, // 미
   349, // 파
   370, // 파#
   392,  // 솔
   415,// 솔#
   440, // 라
   466, // 라#
   494, // 시
   523, //  도
   555 // 레
};

int findBuzzerSysPath()
{
   DIR * dir_info = opendir(BUZZER_BASE_SYS_PATH);
   int ifFound = 0;
   if (dir_info != NULL)
   {
      while (1)
      {   
         struct dirent  *dir_entry;
         dir_entry = readdir (dir_info);
         if (dir_entry == NULL)   break;
         if (strncasecmp(BUZZER_FILENAME, dir_entry->d_name, strlen(BUZZER_FILENAME)) == 0)
         {
            ifFound = 1;
            sprintf(gBuzzerBaseSysDir,"%s%s/",BUZZER_BASE_SYS_PATH,dir_entry->d_name);
         }
      }
   }
   printf("find %s\n",gBuzzerBaseSysDir);

   return ifFound; 
}
static int fdEnable;
static int fdFreq;
int buzzerInit(void)
{
   if ( findBuzzerSysPath()==0 )   return 0;

   char path[200];
   sprintf(path,"%s%s",gBuzzerBaseSysDir,BUZZER_ENABLE_NAME);
   fdEnable=open(path,O_WRONLY);

   sprintf(path,"%s%s",gBuzzerBaseSysDir,BUZZER_FREQUENCY_NAME);
   fdFreq=open(path,O_WRONLY);

   return 1;
}
void buzzerEnable(int bEnable)
{
   if ( bEnable)   write(fdEnable, &"1", 1);
   else          write(fdEnable, &"0", 1);
}
// 1 ~ 1000  Hz
void setFrequency(int frequency) 
{
   dprintf(fdFreq, "%d", frequency);
}
int buzzerExit(void)
{
   buzzerEnable(0);
   close(fdEnable);
   close(fdFreq);
   return 0;
}
int buzzerPlaySong(char scale)
{
   setFrequency(musicScale[scale]);
   buzzerEnable(1);
   return 0;
}
int buzzerStopSong(void)
{
   buzzerEnable(0);
   return 0;
}

int doremi(void)
{
            scale = 0; buzzerPlaySong(scale); //도
            usleep(450000);
            scale=2; buzzerPlaySong(scale); //레
            usleep(150000); 
            scale = 4; buzzerPlaySong(scale); //미
            usleep(450000);
            scale = 0; buzzerPlaySong(scale); //도
            usleep(150000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(300000);
            scale = 0; buzzerPlaySong(scale); //도
            usleep(300000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(900000);
            
            scale=2; buzzerPlaySong(scale); //레
            usleep(450000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(150000);
            scale = 5; buzzerPlaySong(scale); //파
            usleep(150000);
            scale = 5; buzzerPlaySong(scale); //파
            usleep(150000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(150000);
            scale=2; buzzerPlaySong(scale); //레
            usleep(150000);
            scale = 5; buzzerPlaySong(scale); //파
            usleep(900000);
            
            scale =4; buzzerPlaySong(scale); //미
            usleep(450000);
            scale=5; buzzerPlaySong(scale); //파
            usleep(150000);
            scale =7; buzzerPlaySong(scale); //솔
            usleep(450000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(150000);
            scale = 7; buzzerPlaySong(scale); //솔
            usleep(300000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(300000);
            scale = 7; buzzerPlaySong(scale); //솔
            usleep(600000);
            
            scale=5; buzzerPlaySong(scale); //파
            usleep(450000);
            scale = 7; buzzerPlaySong(scale); //솔
            usleep(150000);
            scale = 9; buzzerPlaySong(scale); //라
            usleep(150000);
            scale = 9; buzzerPlaySong(scale); //라
            usleep(150000);
            scale = 7; buzzerPlaySong(scale); //솔
            usleep(150000);
            scale=5; buzzerPlaySong(scale); //파
            usleep(150000);
            scale = 9; buzzerPlaySong(scale); //라
            usleep(900000);
            
            scale=7; buzzerPlaySong(scale); //솔
            usleep(450000);
            scale = 0; buzzerPlaySong(scale); //도
            usleep(150000);
            scale = 2; buzzerPlaySong(scale); //레
            usleep(150000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(150000);
            scale = 5; buzzerPlaySong(scale); //파
            usleep(150000);
            scale=7; buzzerPlaySong(scale); //솔
            usleep(150000);
            scale = 9; buzzerPlaySong(scale); //라
            usleep(900000);
            
            scale=9; buzzerPlaySong(scale); //라
            usleep(450000);
            scale = 2; buzzerPlaySong(scale); //레
            usleep(150000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(150000);
            scale = 5; buzzerPlaySong(scale); //파
            usleep(150000);
            scale = 7; buzzerPlaySong(scale); //솔
            usleep(150000);
            scale=9; buzzerPlaySong(scale); //라
            usleep(150000);
            scale = 11; buzzerPlaySong(scale); //시
            usleep(900000);
            
            scale=11; buzzerPlaySong(scale); //시
            usleep(450000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(150000);
             scale = 6; buzzerPlaySong(scale); //파#
             usleep(150000);
            scale = 8; buzzerPlaySong(scale); //솔#
            usleep(150000);
            scale = 9; buzzerPlaySong(scale); //라
            usleep(150000);
            scale=11; buzzerPlaySong(scale); //시
            usleep(150000);
            scale=12; buzzerPlaySong(scale); //도
            usleep(900000);
            
            
            scale=11; buzzerPlaySong(scale); //시
            usleep(150000);
            scale=10; buzzerPlaySong(scale); //시b
            usleep(150000);
            scale=9; buzzerPlaySong(scale); // 라
            usleep(300000);
            scale = 5; buzzerPlaySong(scale); // 파
            usleep(300000);
            scale = 11; buzzerPlaySong(scale); //시
            usleep(300000);
            scale = 7; buzzerPlaySong(scale); //솔
            usleep(300000);
            scale=12; buzzerPlaySong(scale); //도
            usleep(900000);
}

int plane(void)
{
            scale = 4; buzzerPlaySong(scale); //미
            usleep(450000);
            scale = 2; buzzerPlaySong(scale); //레
            usleep(150000);
            scale = 0; buzzerPlaySong(scale); //도
            usleep(300000);
            scale = 2; buzzerPlaySong(scale); //레
            usleep(300000);
            scale = 4; buzzerPlaySong(scale); //미
             usleep(300000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(300000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(600000);
             
            scale = 2; buzzerPlaySong(scale); //레
            usleep(300000);
            scale = 2; buzzerPlaySong(scale); //레
            usleep(300000);
            scale = 2; buzzerPlaySong(scale); //레
            usleep(600000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(300000);
            scale=7; buzzerPlaySong(scale); //솔
            usleep(300000);
            scale=7; buzzerPlaySong(scale); //솔
            usleep(600000);
            
            scale = 4; buzzerPlaySong(scale); //미
            usleep(450000);
            scale = 2; buzzerPlaySong(scale); //레
            usleep(150000);
            scale = 0; buzzerPlaySong(scale); //도
            usleep(300000);
            scale = 2; buzzerPlaySong(scale); //레
            usleep(300000);
            scale = 4; buzzerPlaySong(scale); //미
             usleep(300000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(300000);
            scale = 4; buzzerPlaySong(scale); //미
            usleep(600000);
