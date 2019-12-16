#ifndef _LCDTEXT_H_
#define _LCDTEXT_H_

//int lcdtextwrite(const char *str1, const char *str2, int linFlag);

void setStrTextLCD(int line, char* str);


#define LCD_DRIVER_NAME "/dev/peritextlcd"

#endif _LCDTEXT_H_

