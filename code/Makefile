CC = gcc
FLAGS = -g -std=c99

all: shuffle subarray stocks

shuffle.o: shuffle.h shuffle.c
	$(CC) $(FLAGS) -c shuffle.c

subarray.o: subarray.h subarray.c
	$(CC) $(FLAGS) -c subarray.c

stocks.o: stocks.h stocks.c
	$(CC) $(FLAGS) -c stocks.c

shuffle: shuffle.o shuffle_main.c
	$(CC) $(FLAGS) -o shuffle shuffle.o shuffle_main.c

subarray: subarray.o shuffle.o subarray_main.c
	$(CC) $(FLAGS) -o subarray shuffle.o subarray.o subarray_main.c

stocks: stocks.o subarray.o shuffle.o stocks_main.c
	$(CC) $(FLAGS) -o stocks shuffle.o subarray.o stocks.o stocks_main.c

clean:
	rm *.o *~ shuffle subarray stocks