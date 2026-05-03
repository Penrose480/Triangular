all: triangular.c
	gcc -o basic triangular.c -lraylib -lm -lpthread -ldl -lrt -lX11
