#include <stdio.h>
#include <stdlib.h>     // for exit
#include <unistd.h>     // for open/close
#include <fcntl.h>      // for O_RDWR
#include <sys/ioctl.h>  // for ioctl
#include <sys/mman.h>
#include <linux/fb.h>   // for fb_var_screeninfo, FBIOGET_VSCREENINFO
#include "bitmap.h"

#define FBDEV_FILE  "/dev/fb0"
#define BIT_VALUE_24BIT   24

int x,y;  // 좌표 선언

int ma (char *argv)
{
    int i, j, k, t;
    int fbfd;
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int coor_x, coor_y;
    int cols = 0, rows = 0;
    int mem_size;

    char    *pData, *data;
    char    r, g, b;
    unsigned long   bmpdata[1280*800];
    unsigned long   pixel;
    unsigned char   *pfbmap;
    unsigned long   *ptr;
    struct  fb_var_screeninfo fbvar;
    struct  fb_fix_screeninfo fbfix;

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");


    read_bmp(argv, &pData, &data, &cols, &rows);
    printf("Bitmap : cols = %d, rows = %d\n", cols, rows);

    for(j = 0; j < rows; j++)
    {
        k   =   j * cols * 3;
        t   =   (rows - 1 - j) * cols;

        for(i = 0; i < cols; i++)
        {
            b   =   *(data + (k + i * 3));
            g   =   *(data + (k + i * 3 + 1));
            r   =   *(data + (k + i * 3 + 2));

            pixel = ((r<<16) | (g<<8) | b);
            bmpdata[t+i]    =   pixel;          // save bitmap data bottom up
        }
    }
    close_bmp(&pData);

    if( (fbfd = open(FBDEV_FILE, O_RDWR)) < 0)
    {
        printf("%s: open error\n", FBDEV_FILE);
        exit(1);
    }

    if( ioctl(fbfd, FBIOGET_VSCREENINFO, &fbvar) )
    {
        printf("%s: ioctl error - FBIOGET_VSCREENINFO \n", FBDEV_FILE);
        exit(1);
    }

    if( ioctl(fbfd, FBIOGET_FSCREENINFO, &fbfix) )
    {
        printf("%s: ioctl error - FBIOGET_FSCREENINFO \n", FBDEV_FILE);
        exit(1);
    }

    if (fbvar.bits_per_pixel != 32)
    {
        fprintf(stderr, "bpp is not 32\n");
        exit(1);
    }

    screen_width    =   fbvar.xres;
    screen_height   =   fbvar.yres;
    bits_per_pixel  =   fbvar.bits_per_pixel;
    line_length     =   fbfix.line_length;
    mem_size    =   line_length * screen_height;
    
    printf("screen_width : %d\n", screen_width);
    printf("screen_height : %d\n", screen_height);
    printf("bits_per_pixel : %d\n", bits_per_pixel);
    printf("line_length : %d\n", line_length);

    pfbmap  =   (unsigned char *)
        mmap(0, mem_size, PROT_READ|PROT_WRITE, MAP_SHARED, fbfd, 0);

    if ((unsigned)pfbmap == (unsigned)-1)
    {
        perror("fbdev mmap\n");
        exit(1);
    }
    unsigned long background[600][1024];
    memset(background, 0, 600*1024*4);

    // fb clear - black
    for(coor_y = 0; coor_y < screen_height; coor_y++) {
        ptr =   (unsigned long *)background + (screen_width * coor_y);
        for(coor_x = 0; coor_x < screen_width; coor_x++)
        {
            *ptr++  =   0x000000;
        }
    }
   memcpy(pfbmap, background, 600*1024*4);
    
   // direction for image generating : (0,0)-> (1,0)-> (2,0)-> ...-> (row, column)
    for(coor_y = 0; coor_y < rows; coor_y++) {
        ptr =   (unsigned long*)background+ (screen_width * coor_y);
        for (coor_x = 0; coor_x < cols; coor_x++) {
            *ptr++  =   bmpdata[coor_x + coor_y*cols];
        }
    }
    
    
      for (y=100; y<150;y++)
      for (x=100;x<150;x++)
      background[y][x] = 0x00ff00;
      memcpy(pfbmap, background, 600*1024*4);
      
      munmap( pfbmap, mem_size);
      close( fbfd);
      return 0;
}
