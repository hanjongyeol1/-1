#LED Piano
CC=arm-linux-gnueabi-gcc
AR=arm-linux-gnueabi-ar

all: libtetLib.a piano.elf

piano.elf: main.o libtetLib.a button.h buzzer.h led.h bitmap.h
	$(CC) --static main.o -o piano.elf -ltetLib -L. -lpthread

libtetLib.a: button.o buzzer.o led.o bitmap.o
	$(AR) rc libtetLib.a button.o buzzer.o led.o bitmap.o

main.o : main.c
button.o: button.c button.h
buzzer.o: buzzer.c buzzer.h
led.o: led.c led.h
bitmap.o : bitmap.c bitmap.h

clean:
	rm -f *.elf *.o *.a
