final.elf: 1.o 2.o 3.o 4.o main.o
	gcc 1.o 2.o 3.o 4.o main.o -o final.elf 
   
1.o:1.c myProject.h
	gcc -c -o 1.o 1.c
2.o:2.c myProject.h
	gcc -c -o 2.o 2.c
3.o:3.c myProject.h
	gcc -c -o 3.o 3.c
4.o:4.c myProject.h
	gcc -c -o 4.o 4.c
main.o:main.c myProject.h
	gcc -c -o main.o main.c
