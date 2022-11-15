all: src/*/*.h src/*/*.c main.c
	cc src/*/*.h src/*/*.c main.c -o run.out