all: basic.c
	gcc -o basic basic.c -lraylib -lm -lpthread -ldl -lrt -lX11
