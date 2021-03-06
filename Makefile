CC=gcc 
CFLAGS = -std=c99 -I. -std=c99 -g

DEPS = hashset.h 
OBJS = hashset.o test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJS)
	$(CC) -g -o $@ $^ $(CFLAGS)

clean:
	rm -f test *.o

