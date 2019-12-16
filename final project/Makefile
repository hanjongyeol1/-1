#LED Piano
CC=arm-linux-gnueabi-gcc
AR=arm-linux-gnueabi-ar

all: piano.elf

piano.elf: main.o libtetLib.a
	$(CC) --static main.o -o piano.elf -ltetLib -L. -lpthread

libtetLib.a:   button.o buzzer.o led.o bitmap.o lcdtext.o fnd.o
	$(AR) rc libtetLib.a button.o buzzer.o led.o bitmap.o lcdtext.o fnd.o

main.o : main.c button.h buzzer.h led.h bitmap.h lcdtext.h fnd.h libtetLib.a
button.o: button.c button.h
buzzer.o: buzzer.c buzzer.h
led.o: led.c led.h
bitmap.o : bitmap.c bitmap.h
lcdtext.o : lcdtext.c lcdtext.h
fnd.o : fnd.c fnd.h
#위 세개의 o 파일은 암묵적 makefile 규칙에 의해 자동 생성됨

clean:
	rm -f *.elf *.o *.a

