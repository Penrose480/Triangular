all: triangular.c
	gcc -o triangular triangular.c -lraylib -lm -lpthread -ldl -lrt -lX11
