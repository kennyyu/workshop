CC = gcc
FLAGS = -g -std=c99
INCLUDES = shuffle.h lib.h stocks.h subarray.h
PROG = shuffle subarray stocks

%.o: %.c $(INCLUDES)
	$(CC) $(FLAGS) -o $@ -c $<

all: $(PROG)

shuffle: shuffle.o lib.o shuffle_main.o
	$(CC) $(FLAGS) -o $@ $^

subarray: subarray.o shuffle.o lib.o subarray_main.o
	$(CC) $(FLAGS) -o $@ $^

stocks: subarray.o stocks.o shuffle.o lib.o stocks_main.o
	$(CC) $(FLAGS) -o $@ $^

clean:
	rm *.o *~ $(PROG)